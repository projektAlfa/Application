using System;
using System.Collections.Generic;
using System.Text;

using System.IO;
using System.Reflection;

using Newtonsoft.Json;

namespace JsonApp.CustomPages.model {
    class JSONparser {
        public void parseJsonToBuildingsList( string _jsonFileName, ref model.BuildingsList _list ) {
            var assembly = typeof(listDisplay).GetTypeInfo().Assembly;
            Stream stream = assembly.GetManifestResourceStream($"{assembly.GetName().Name}.{_jsonFileName}");
            using (var reader = new StreamReader(stream)) {
                var json = reader.ReadToEnd();
                _list.Buildings = JsonConvert.DeserializeObject<List<model.Building>>(json);
            }
        }
    }
}
