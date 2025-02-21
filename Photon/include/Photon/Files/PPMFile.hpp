#pragma once

#include "File.hpp"

namespace Photon
{
    // TODO: Stub code
    // TODO: Implement
    // TODO: Doc comments
    // TODO: Unit Tests?

    enum PPM_FORMAT
    {
        P3,
        P6
    };

    class PPMFile : public File
    {
    public:
        PPMFile(std::string path, unsigned int width, unsigned int height, PPM_FORMAT format);
        ~PPMFile();

        bool Save(std::vector<Color> buffer) override;

    protected:
    private:
        unsigned int m_width;
        unsigned int m_height;
        PPM_FORMAT m_format;
    };
}