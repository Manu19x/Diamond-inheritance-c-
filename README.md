# Diamond-inheritance-c ++

This is a C++ program that defines a set of classes related to snow removal tools and drones, and provides their functionality.

The program begins with the declaration of a pure virtual class named IOStream, which contains a virtual function Print that is used to output information about objects of the derived classes. The insertion operator (<<) is then overloaded to output objects of any class derived from IOStream.

The class Unelte is an abstract base class for all the snow removal tools that will be derived from it. It contains the private data members nume (name), serie (series), and nrserie (serial number), and provides public methods for accessing and modifying them. It also contains two pure virtual functions GetTimpDezapezire (get snow removal time) and GetConsumEnergie (get energy consumption), which will be implemented by its derived classes.

The class Lopataelec is a derived class from Unelte that represents an electric shovel. It has the additional private data members supfaras (surface area), capbat (battery capacity), and supcuratata (cleaned surface area), and public methods for accessing and modifying them. It overrides the Print, GetTimpDezapezire, and GetConsumEnergie functions to provide their specific implementation for electric shovels.

The class Drone is another derived class from Unelte that represents a drone for snow removal. It has the additional private data members altmax (maximum altitude), nrmotoare (number of engines), and supcuratataa (cleaned surface area), and public methods for accessing and modifying them. It also overrides the GetTimpDezapezire and GetConsumEnergie functions to provide their specific implementation for drones.
