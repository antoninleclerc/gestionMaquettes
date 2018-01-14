#ifndef ECUE_H
#define ECUE_H

#include <fstream>
#include "Cours.h"

/**	@class ECUE
 *	@brief classe représentant une ECUE
 */
class ECUE : public Cours {
	public:
		/**	Constructeur d'une ECUE
		 *	@brief Constructeur d'ECUE à partir d'un code, d'un intitulé, d'un coefficient, des heures CM, des heures TD et des heures TP
		 *	@param[in] code : code d'une ECUE
		 *	@param[in] intitule : l'intitule d'une ECUE
		 *	@param[in] coefficient : coefficient d'une ECUE
		 * 	@param[in] heuresCM : nombre d'heures de CM d'une ECUE
		 *	@param[in] heuresTD : nombre d'heures de TD d'une ECUE
		 	@param[in] heuresTP : nombre d'heures de TP d'une ECUE
		 */
		ECUE(const std::string &code, const std::string &intitule, int coefficient, int heuresCM, int heuresTD, int heuresTP);
		
		/**	Destructeur d'une ECUE
		 */
		~ECUE();
		
		/** Fonction heuresCM 
		 *	@return Le nombre d'heures CM d'une ECUE
		 */
		int heuresCM() const;
		
		/** Fonction heuresTD
		 *	@return Le nombre d'heures TD d'une ECUE
		 */
		int heuresTD() const;
		
		/** Fonction heuresTP 
		 *	@return Le nombre d'heures TP d'une ECUE
		 */
		int heuresTP() const;
		
		/**	Fonction modifierHeuresCM
		 *	Permet de modifier le nombre d'heures CM d'une ECUE
		 *	@param[in] heuresCM Le nouveau nombre d'heures CM de l'ECUE
		 */
		void modifierHeuresCM(int heuresCM);
		
		/**	Fonction modifierHeuresTD
		 *	Permet de modifier le nombre d'heures TD d'une ECUE
		 *	@param[in] heuresCM Le nouveau nombre d'heures TD de l'ECUE
		 */
		void modifierHeuresTD(int heuresTD);
		
		/**	Fonction modifierHeuresTP
		 *	Permet de modifier le nombre d'heures TP d'une ECUE
		 *	@param[in] heuresCM Le nouveau nombre d'heures TP de l'ECUE
		 */
		void modifierHeuresTP(int heuresTP);
		
		/** Fonction affiche
		 *	Permet d'afficher une ECUE
		 */
		void affiche(std::ostream& ost) const;
		/**	Fonction enregistrerECUE
 		 *	Permet d'enregistrer une ECUE dans le fichier txt portant le nom de la mention de la formation � laquelle appartient l'ECUE
 		 *	@param[in] mention : le nom du fichier txt
 		 */
 		void enregistrerECUE(const std::string &mention) const;
		
	private:
		/**	Données privées d'une ECUE
		 */
		int d_heuresCM, d_heuresTD, d_heuresTP;
};

#endif
