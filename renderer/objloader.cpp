#include "objloader.h"
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>

using namespace std;

namespace
{
vector<string> split(const string& input, const char delimiter)
{
   vector<string> splitString;

   istringstream iss(input);
   string currentString;
   while (getline(iss, currentString, delimiter)) {
      splitString.push_back(currentString);
   }

   return splitString;
}
} // namespace

Model::Model(const string_view fileName) : m_filename{fileName} {}

bool Model::parseObj()
{
   ifstream objFile(m_filename);

   if (!objFile.is_open()) {
      return false;
   }

   string currentLine;
   while (getline(objFile, currentLine)) {
      if (currentLine.compare(0, 2, "v ") == 0) {
         istringstream vertexTokens(currentLine.substr(2));
         Vertex vertex;
         vertexTokens >> vertex.x >> vertex.y >> vertex.z;
         m_vertices.push_back(vertex);
      }
      else if (currentLine.compare(0, 2, "f ") == 0) {
         istringstream faceTokens(currentLine.substr(2));

         Face face;

         string faceData;
         for (const auto _ : views::iota(0, 3)) {
            faceTokens >> faceData;
            const auto vertexData = split(faceData, '/');

            // Vertex
            auto vertexIndex = stoi(vertexData.at(0));
            face.m_vertexIndices.push_back(--vertexIndex);

            // Texture Coordinates
            // TODO

            // Normals
            // TODO
         }
         m_faces.push_back(face);
      }
   }

   objFile.close();
   return true;
}