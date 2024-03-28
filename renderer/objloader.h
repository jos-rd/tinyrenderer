#pragma once

#include <string>
#include <string_view>
#include <vector>

struct Vertex
{
   float x;
   float y;
   float z;
};

struct Face
{
   std::vector<unsigned int> m_vertexIndices;
};

class Model
{
public:
   Model(std::string_view fileName);
   bool parseObj();

   int getNumberOfVertices() const
   {
      return static_cast<int>(m_vertices.size());
   }

   int getNumberOfFaces() const { return static_cast<int>(m_faces.size()); }

   Vertex getVertex(int idx) const { return m_vertices.at(idx); }

   Face getFace(int idx) const { return m_faces.at(idx); }

   const std::vector<Vertex>& getVertices() const { return m_vertices; }

   const std::vector<Face>& getFaces() const { return m_faces; }

private:
   std::vector<Vertex> m_vertices;
   std::vector<Face> m_faces;
   std::string m_filename;
};