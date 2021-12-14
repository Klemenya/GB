#pragma once

namespace University
{
    class IRepository
    {
        virtual void Open() = 0; 
        virtual void Save() = 0; 
    };
}