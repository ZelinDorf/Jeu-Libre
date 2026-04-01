#pragma once
#include <fstream>
#include "Scene.h"
//#include <wincodec.h>

namespace JSONParser
{
    struct JsonObj
    {
        static cpu_entity* JsonLoader(String const& _path, Scene* _pScene)
        {
            Vector<cpu_mesh> vObject;
            cpu_entity* pEntity = new cpu_entity;

            if (_pScene == nullptr) return pEntity;

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
            json jObjects = j["objects"];
            for (int i = 0; i < jObjects.size(); i++)
            {
                json currentObj = jObjects[i];

                cpu_mesh tempMesh = CreateMesh(currentObj);
                
                cpu_material* mat;
                
                vObject.push_back(tempMesh);

                if (currentObj.contains("_texture") && currentObj["_texture"].is_string())
                {
                    String path;
                    path.append("res/Texture/Chunk_Texture");
                    path.append(currentObj["_texture"].get<String>());

                    mat = RessourcesManager::GetMatWithName(path);
                }
                else if (currentObj.contains("texture") && currentObj["texture"].is_string())
                {
                    String path;
                    path.append("res/Texture/");
                    path.append(currentObj["_texture"].get<String>());

                    mat = RessourcesManager::GetMatWithName(path);
                }

                //  POS / SCALE / ROT
                /////////////////////

                {
                    XMFLOAT3 position;
                    position.x = currentObj["position"][0].get<float>();
                    position.y = currentObj["position"][2].get<float>();
                    position.z = currentObj["position"][1].get<float>();
                    pEntity->transform.SetPosition(position);

                    XMFLOAT3 scale;
                    scale.x = currentObj["scale"][0].get<float>();
                    scale.y = currentObj["scale"][2].get<float>();
                    scale.z = currentObj["scale"][1].get<float>();
                    pEntity->transform.Scale(scale);

                    float rotX = currentObj["rotation"][0].get<float>();
                    float rotY = currentObj["rotation"][1].get<float>();
                    float rotZ = currentObj["rotation"][2].get<float>();
                    float rotW = currentObj["rotation"][3].get<float>();
                    XMFLOAT4 rotation(rotX, rotY, rotZ, -rotW);
                    pEntity->transform.SetRotation(rotation);
                }

                //collider TODO

                //Add to scene?

            }

            cpu_mesh entMesh;

            for (cpu_mesh& m : vObject)
            {
                entMesh.AddMesh(m);
            }

            return pEntity;
        }

    private:
        static cpu_mesh CreateMesh(json const& _obj)//construit la geo/mesh custom
        {
            cpu_mesh m;

            Vector<cpu_vertex> ver = LoadObj(_obj);

            for (cpu_vertex& v : ver)
            {
                cpu_vertex ve;
                ve.pos = { v.pos.x, v.pos.y, v.pos.z };
                ve.normal = { v.normal.x, v.normal.y, v.normal.z };
                ve.uv = { v.uv.x, 1.f - v.uv.y };
                m.vertices.push_back(ve);
            }

            //reconstruire le mesh + return

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
                posV.y = vVertices[vIndex * 3 + 2].get<float>();
                posV.z = vVertices[vIndex * 3 + 1].get<float>();

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
