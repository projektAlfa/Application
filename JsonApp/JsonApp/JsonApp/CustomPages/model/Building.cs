using System;
using System.Collections.Generic;
using System.Text;

namespace JsonApp.CustomPages.model {
    public class Building {
        string _id;
        string _name;
        string _campus;
        int _x;
        int _y;

        public string Id { get { return _id; } set { _id = value; } }
        public string Name { get { return _name; } set { _name = value; } }
        public string Campus { get { return _campus; } set { _campus = value; } }
        public int X { get { return _x; } set { _x = value; } }
        public int Y { get { return _y; } set { _y = value; } }
    }

    public class BuildingsList {
        List<Building> _buildings;
        public List<Building> Buildings { get { return _buildings; } set { _buildings = value; } }
    }
}
