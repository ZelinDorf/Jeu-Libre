#pragma once
#include <fstream>
#include "Scene.h"
//#include <wincodec.h>

namespace JSONParser
{
    struct JsonObj
    {
        static void JsonLoader(String const& _path, Scene* _pScene, cpu_entity*& _pEnt)
        {
            /*
            load json
            for(obj.size)
            createAllTriangles

            if("texture")
            setTexture

            {pos, scale, rot}

            collider

            ++add entity to scene (or not if somewhere else)
            }
            */

            Vector<cpu_mesh*> vObject;
            _pEnt = cpuEngine.CreateEntity();

            if (_pScene == nullptr) return;

            std::ifstream file(_path);
            if (!file.is_open()) 
                std::cerr << "Couldn't open JSON file\n";

            json j;
            try {
                file >> j;
            }
            catch (json::parse_error& e) {
                std::cerr << "Parsing error: " << e.what() << "\n";
            }

            json jObjects = j["objects"];
            for (int i = 0; i < jObjects.size(); i++)
            {
                json currentObj = jObjects[i];

                cpu_mesh* tempMesh = CreateMesh(currentObj);              

                cpu_material* mat;
                
                vObject.push_back(tempMesh);

                if (currentObj.contains("texture") && currentObj["texture"].is_string())
                {
                    String path;
                    //path.append(TEXTURE_PATH);
                    path.append(currentObj["texture"].get<String>());

                    mat = RessourcesManager::GetMatWithName(path);
                    _pEnt->pMaterial = mat;
                }

                //  POS / SCALE / ROT
                /////////////////////

                {
                    XMFLOAT3 position;
                    position.x = currentObj["position"][0].get<float>();
                    position.y = currentObj["position"][2].get<float>();
                    position.z = currentObj["position"][1].get<float>();
                    _pEnt->transform.SetPosition(position);

                    XMFLOAT3 scale;
                    scale.x = currentObj["scale"][0].get<float>();
                    scale.y = currentObj["scale"][2].get<float>();
                    scale.z = currentObj["scale"][1].get<float>();
                    _pEnt->transform.SetScaling(scale);

                    float rotX = currentObj["rotation"][0].get<float>();
                    float rotY = currentObj["rotation"][1].get<float>();
                    float rotZ = currentObj["rotation"][2].get<float>();
                    float rotW = currentObj["rotation"][3].get<float>();
                    XMFLOAT4 rotation(rotX, rotY, rotZ, -rotW);
                    _pEnt->transform.SetRotation(rotation);
                }

                //collider TODO

                //Add to scene?

            }

            cpu_mesh* entMesh = new cpu_mesh;

            for (cpu_mesh* m : vObject)
            {
                entMesh->AddMesh(*m);
            }

            entMesh->Optimize();

            _pEnt->pMesh = entMesh;

            if (_pEnt->pMaterial == nullptr)
            {
                _pEnt->pMaterial = new cpu_material;
                _pEnt->pMaterial->color = CPU_RED;
            }

            constexpr float yaw = XMConvertToRadians(180.f);
            //float pitch = XMConvertToRadians(-90.f);

            _pEnt->transform.SetYPR(yaw);

            return;
        }

    private:
        static cpu_mesh* CreateMesh(json const& _obj)//construit la geo/mesh custom
        {
            String name;
            name.append(_obj["name"].get<String>());
            
            cpu_mesh* m = RessourcesManager::GetMeshWithName(name);

            if (m->vertices.size() <= 0)
            {
                Vector<cpu_vertex> ver = LoadObj(_obj);

                for (cpu_vertex& v : ver)
                {
                    m->vertices.push_back(v);
                }
            }

            return m;
        }

        static Vector<cpu_vertex> LoadObj(json const& _obj)//recup les vetices avec pos rot et normal
        {
            Vector<cpu_vertex> vVertex;

            json mesh = _obj["mesh"];
            json vVertices = mesh["vertices"];
            json indices = mesh["indices"];
            json uvs = mesh["uvs"];
            json normals = mesh["normals"];

            int vertexCount = (int)vVertices.size() / 3;
            int loopCount = (int)indices.size(); // 3 loops per triangle

            for (int i = 0; i < loopCount; i++)
            {
                int vIndex = indices[i].get<int>();

                // POSITION
                XMFLOAT3 posV;
                posV.x = vVertices[vIndex * 3 + 0].get<float>();
                posV.y = vVertices[vIndex * 3 + 1].get<float>();
                posV.z = vVertices[vIndex * 3 + 2].get<float>();

                // UV
                XMFLOAT2 uvV;
                uvV.x = uvs[i * 2 + 0].get<float>();
                uvV.y = uvs[i * 2 + 1].get<float>();

                // NORMAL
                XMFLOAT3 normalV;
                normalV.x = normals[i * 3 + 0].get<float>();
                normalV.y = normals[i * 3 + 1].get<float>();
                normalV.z = normals[i * 3 + 2].get<float>();

                cpu_vertex v;
                v.pos = posV; v.uv = uvV; v.normal = normalV;

                vVertex.push_back(v);
            }

            return vVertex;
        }

    };
};

using namespace JSONParser;

/*-----------------------------------------------------
Map_Loader :
get path && check
if yes -> create object
then set all

=======================================================



-----------------------------------------------------*/
