#include "earthquake.h"

void Earthquake::set_id(string &ID)
{
    eyedee = ID;
}

string Earthquake::get_id()
{
    return eyedee;
}


// sabber 

// This function checks the validity of magnitude type

bool Earthquake::set_mag_type(string magType)
{
    changetoupper(magType);
    if(magType == "ML")
    {
        magnitude_type = ML;
        return true;
    } else if (magType == "MS")
    {
        magnitude_type = MS;
        return true;
    } else if (magType == "MB")
    {
        magnitude_type = MB;
        return true;
    } else if (magType == "MW")
    {
        magnitude_type = MW;
        return true;
    } else
    {
        return false;
    }
}


// Get Earthquake magnitude type for output
string Earthquake::getMagType()
{
    if (magnitude_type == ML) return "ML";
    if (magnitude_type == MS) return "MS";
    if (magnitude_type == MB) return "MB";
    if (magnitude_type == MW) return "MW";
    exit(EXIT_FAILURE);
}
