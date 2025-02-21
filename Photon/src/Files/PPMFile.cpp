#include "Files/PPMFile.hpp"

namespace Photon
{
    PPMFile::PPMFile(std::string path, unsigned int width, unsigned int height, PPM_FORMAT format)
        : File(path)
    {
        m_width = width;
        m_height = height;
        m_format = format;
    }

    PPMFile::~PPMFile()
    {
        // NOTE: Currently does nothing
    }

    bool PPMFile::Save(std::vector<Color> buffer)
    {
        // Write PPM Header
        std::string format;
        switch (m_format)
        {
        case PPM_FORMAT::P3:
            format = "P3";
            break;
        case PPM_FORMAT::P6:
            format = "P6";
            break;
        default:
            return false;
        }

        m_file << format << std::endl
               << m_width << ' ' << m_height << std::endl
               << "255" << std::endl;

        // Write image to file
        for (Color color : buffer)
        {
            // Convert float channels to int
            int ir = static_cast<int>(255.999 * color.GetR());
            int ig = static_cast<int>(255.999 * color.GetG());
            int ib = static_cast<int>(255.999 * color.GetB());

            m_file << ir << ' ' << ig << ' ' << ib << std::endl;
        }

        return true;
    }
}