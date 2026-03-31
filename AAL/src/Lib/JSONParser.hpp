#pragma once
#include <fstream>
#include <wincodec.h>

namespace JSONParser
{
    struct JsonObj
    {
        static cpu_entity* JsonLoader(String const& _path, Scene* _pScene)
        {
            Vector<cpu_mesh*> vObject;
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

            json jObjects = j["objects"];
            for (int i = 0; i < jObjects.size(); i++)
            {
                json currentObj = jObjects[i];

                /*cpu_mesh tempMesh;
                Vector<cpu_triangle> vTri = CreateAllTriangles(currentObj);
                for (cpu_triangle tri : vTri)
                {
                    tempMesh.AddTriangle(tri);
                }*/


            }
            /*
            load json
            for(obj.size)
            createAllTriangles

            if("texture")
            setTexture

            {pos, scale, rot}

            collider
            }            
            */

            return pEntity;
        }

    private:
        static Vector<cpu_mesh> CreateAllTriangles(json const& _obj)
        {
            Vector<cpu_triangle> vTriangles;

            Vector<cpu_mesh> vMesh;

            return vMesh;
        }

        static Vector<cpu_mesh> LoadObj(json const& _obj)//recup les vetices avec pos rot et normal
        {
            Vector<cpu_mesh> vMesh;

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

                cpu_mesh m;

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

                m.vertices.push_back(v);
                vMesh.push_back(m);
            }

            return vMesh;
        }

    };
};

/*-----------------------------------------------------
Map_Loader :
get path && check
if yes -> create object
then set all

=======================================================

#include "RessourceManager.h"

struct MapLoader
{
    static std::vector<GameObject*> LoadMap(String const& path, Scene* pScene)
    {
        std::vector<GameObject*> vAllObjects;

        if (pScene == nullptr) return vAllObjects;

        Map<GameObject*, String> mObjects;


        std::ifstream file(path);
        if (!file.is_open()) {
            std::cerr << "Impossible d'ouvrir le fichier JSON\n";
        }
        json j;
        try {
            file >> j;
        }
        catch (json::parse_error& e) {
            std::cerr << "Erreur de parsing: " << e.what() << "\n";
        }

        json jObjects = j["objects"];
        for (int i = 0; i < jObjects.size(); ++i)
        {
            json currObject = jObjects[i];
            GameObject& gameObject = GameObject::Create(*pScene);
            MeshRenderer& mesh = *gameObject.AddComponent<MeshRenderer>();
            mesh.SetGeometry(GeometryFactory::LoadJsonGeometry(currObject));
            mesh.pGeometry->name = currObject["name"].get<String>();
            gameObject.SetName(mesh.pGeometry->name.c_str());

            vAllObjects.push_back(&gameObject);

            if (currObject.contains("_texture") && currObject["_texture"].is_string())
            {
                std::string texturePath;
                texturePath.append("res/Textures/Rooms_Textures");
                texturePath.append(currObject["_texture"].get<std::string>());
                Texture* texture = RessourceManager::GetTextureWithName(texturePath);;
                mesh.SetAlbedoTexture(texture);
            }
            else if (currObject.contains("texture") && currObject["texture"].is_string())
            {
                std::string texturePath;
                texturePath.append("res/Textures/");
                texturePath.append(currObject["texture"].get<std::string>());
                Texture* texture = RessourceManager::GetTextureWithName(texturePath);
                mesh.SetAlbedoTexture(texture);
            }

            // Pos / Scale / Rot
            {
                XMFLOAT3 position;
                position.x = currObject["position"][0].get<float>();
                position.y = currObject["position"][2].get<float>();
                position.z = currObject["position"][1].get<float>();
                gameObject.transform.SetLocalPosition(position);

                XMFLOAT3 scale;
                scale.x = currObject["scale"][0].get<float>();
                scale.y = currObject["scale"][2].get<float>();
                scale.z = currObject["scale"][1].get<float>();
                gameObject.transform.SetLocalScale(scale);

                float32 rotX = currObject["rotation"][0].get<float>();
                float32 rotY = currObject["rotation"][1].get<float>();
                float32 rotZ = currObject["rotation"][2].get<float>();
                float32 rotW = currObject["rotation"][3].get<float>();
                Quaternion rotation(rotX, rotY, rotZ, -rotW);
                gameObject.transform.SetLocalRotation(rotation);
            }

            if (currObject.contains("has_collider") && currObject["has_collider"].is_boolean() && currObject["has_collider"].get<bool>() == true)
            {
                if (currObject["has_collider"].get<bool>())
                    BoxCollider* b = gameObject.AddComponent<BoxCollider>();
            }
        }

        return vAllObjects;
    }
};

-----------------------------------------------------*/
