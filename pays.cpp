#include <iostream>
#include <fstream>
#include "./lib/nlohmann/json.hpp"
#include <string>

using json = nlohmann::json;

std::string getCityName(std::string country) {
    /*Renvoie le nom de la capitale pour un country donné. Dépend de:
    <json>, <string>
    std::string -> std::string 
    */

    std::ifstream f("country-by-capital-city.json"); // Lire fichier
    json data = json::parse(f); // fichier -> liste de dict

    for (int i = 0; i<244; i++) {               // 244: nb de pays; algo à améliorer (efficacité basse) mais correct pour ce faible nb de pays
        if (data[i]["country"] == country) {    // Pour chaque valeur de la liste, vérifier si elle correspond au pays demandé
            return data[i]["city"];             // Si elle correspond, renvoyer la valeur du dict pour la clé "city"
        }
    }
    return "Error"; // Pays non présent dans country-by-capital-city.json
}

int main() {   
    std::string country;                            // Récupérer Entrée de l'utilisateur.
    std::cout << "Pays (syntaxe anglophone): ";     // Afficher la requête
    std::getline(std::cin, country);                // Et l'enregistrer dans country

    std::string cityName = getCityName(country);

    if (cityName != "Error") {                                                                      // Si le pays est bien contenu dans la liste...
        std::cout << "La capitale du pays " << country << " est " << cityName << "." << std::endl;  // Afficher la capitale pour ce pays donné
        return 0;
    }
    std::cout << "Le pays donné n'est pas compris dans la liste des pays. Veuillez recommencer." << std::endl; // Erreur de l'utilisateur
    return 1;
}