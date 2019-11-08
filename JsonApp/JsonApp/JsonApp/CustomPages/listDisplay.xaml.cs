using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace JsonApp.CustomPages {
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class listDisplay : ContentPage {
        private model.BuildingsList buildingsList = new model.BuildingsList();
        private model.JSONparser parser = new model.JSONparser();
        private string dataFilePath = "CustomPages.data.buildings.json";

        public listDisplay() {
            InitializeComponent();
            parser.parseJsonToBuildingsList(dataFilePath, ref buildingsList);
            buildingsListView.ItemsSource = GetBuildings();
            var imgSource = ImageSource.FromResource("JsonApp.CustomPages.data.map.jpg");
            mapImg.Source = imgSource;
        }

        List<model.Building> GetBuildings( string searchText = null ) {
            if(String.IsNullOrWhiteSpace(searchText))
                return buildingsList.Buildings;
            return buildingsList.Buildings.Where(building => 
                        building.Id.ToLower().StartsWith(searchText.ToLower()) ||
                        building.Name.ToLower().StartsWith(searchText.ToLower()) 
                    ).ToList();
        }

        private void SearchBar_TextChanged( object sender, TextChangedEventArgs e ) {
            buildingsListView.ItemsSource = GetBuildings(e.NewTextValue);
        }

        private void SearchBar_Focused( object sender, FocusEventArgs e ) {
            buildingsListView.IsVisible = true;
        }

        private void SearchBar_Unfocused( object sender, FocusEventArgs e ) {
            buildingsListView.IsVisible = false;
        }
    }
}