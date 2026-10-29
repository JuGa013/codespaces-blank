### Exercice 1

```
DEBUT
    ASSIGNE annees_permis
    ASSIGNE est_suspendu
    ASSIGNE a_autorisation

    ECRIRE "Entrez le nombre d'années de permis de l'accompagnateur :"
    LIRE annees_permis

    ECRIRE "Le permis a-t-il dejà été suspendu ?"
    LIRE est_suspendu

    ECRIRE "A-t-il l'autorisation de l'assurance ?"
    LIRE a_autorisation

    SI annees_permis >= 5 ET est_suspendu est FAUX ET a_autorisation est VRAI
        ECRIRE "Resultat : La personne est un accompagnateur valide."
    SINON
        ECRIRE "Resultat : La personne n'est PAS un accompagnateur valide."
    FINSI
FIN
```

### Exercice 2

```
FONCTION est_premiere_semaine_decembre()
    ASSIGNE aujourdhui
    ASSIGNE mois
    ASSIGNE jour

    aujourdhui = APPELLE date()

    mois = (aujourdhui / 100) % 100
    jour = aujourdhui % 100

    RETOURNE (mois == 12 ET jour >= 1 ET jour <= 7)
FINFONCTION

FONCTION calcul_total(montant_total, promo_est_active)
    ASSIGNE reduction = 0
    ASSIGNE montant_final = montant_total

    SI promo_est_active est VRAI ET montant_total > 500.0
        reduction = montant_total * 0.10
        montant_final = montant_total - reduction
    FINSI

    ECRIRE "Montant initial : <montant_total> EUR"
    ECRIRE "Montant de la réduction : <reduction> EUR"
    ECRIRE "Montant total payé : <montant_final> EUR"
FINFONCTION

DEBUT
    ASSIGNE prix_article
    ASSIGNE montant_total = 0
    ASSIGNE plafond_atteint = FAUX
    ASSIGNE promo_est_active = APPELLE est_premiere_semaine_decembre()

    TANTQUE VRAI
        ECRIRE "Voulez vous ajouter un article ?"
        LIRE ajout_article
        SI ajout_article est FAUX
            break
        FINSI
        
        ECRIRE "Prix de l'article : "
        LIRE prix_article

        montant_total = montant_total + prix_article

        SI promo_est_active est VRAI ET plafond_atteint est FAUX ET montant_total > 500.0
            ECRIRE "Vous avez atteint le plafond pour bénéficier des 10% de réduction !"
            plafond_atteint = VRAI
        FINSI
    FINTANTQUE

    APPELLE calcul_total(montant_total, promo_est_active)
FIN
```

### Exercice 3

```
DEFINI LIMITE = 90

DEBUT
    ASSIGNE vitesse_actuelle

    ECRIRE "=== Système de gestion du limitateur de vitesse (90 km/h) ==="
    ECRIRE "Entrez 0 pour arrêter la simulation."

    TANTQUE VRAI
        vitesse_actuelle = APPELLE revele_vitesse()

        SI vitesse_actuelle == 0
            ECRIRE "Arret du véhicule / Fin de la simulation."
            break
        FINSI

        SI vitesse_actuelle > LIMITE
            ECRIRE "/!\ ALERTE TABLEAU DE BORD : Vitesse limite de 90km/h dépassée ! /!\"

            TANTQUE vitesse_actuelle > LIMITE
                ECRIRE "ALARME SONORE : BIP ! BIP !"
                APPELLE ATTENDRE(5)

                vitesse_actuelle = APPELLE revele_vitesse()

                SI vitesse_actuelle <= LIMITE
                    ECRIRE "Retour sous la limite de 90 km/h. Arret de l'alarme et disparition du message."
                FINSI
            FINTANTQUE
        SINON
            APPELLE ATTENDRE(5)
        FINSI
    FINTANTQUE
FIN
```

### Exercice 4

```
DEBUT
    ASSIGNE age
    ASSIGNE est_etudiant
    ASSIGNE prix_entree

    ASSIGNE prix_total = 0
    ASSIGNE nb_cadeaux = 0

    ECRIRE "Combien de visiteurs y a-t-il dans le groupe ? :"
    LIRE nombre_visiteurs

    POUR i allant de 1 à nombre_visiteurs
        ECRIRE "Entrez l'âge du visiteur <i> :"
        LIRE age

        ECRIRE "Le visiteur est-il étudiant ?"
        LIRE est_etudiant

        prix_entree = 12

        SI age < 12
            prix_entree = 0
            nb_cadeaux = nb_cadeaux + 1
        SINON SI age > 65
            prix_entree = 0
        SINON SI est_etudiant est VRAI
            prix_entree = 5
        FINSI

        prix_total = prix_total + prix_entree
    FINPOUR

    ECRIRE "Prix total des entrées : ", prix_total, " EUR"
    ECRIRE "Nombre de cadeaux à distribuer : ", nb_cadeaux
FIN
```

### Exercice 5

```
DEBUT
    ECRIRE "Entrez le montant de l'achat :"
    LIRE montant_achat

    ASSIGNE pays_achat = APPELLE localisation()
    ASSIGNE score_risque = APPELLE score_risque()

    SI montant_achat > 1000.0 OU pays_achat != "France" OU score_risque > 80
        ECRIRE "ALERTE : Le système anti-fraude 3D Secure est déclenché !"
    FINSI

    // SI montant_achat <= 1000.0 ET pays_achat == "France" ET score_risque <= 80
    //     ECRIRE "Pas de déclenchement du 3D Secure."
    // FINSI
FIN
```

### Exercice 6

```
FONCTION taux_vers_euro(devise)
    SELON devise
        CAS "GBP":
            RETOURNE 0.85
        CAS "USD":
            RETOURNE 1.12
        CAS "JPY":
            RETOURNE 176.89
        DEFAUT:
            RETOURNE 1
    FINSELON
FINFONCTION

FONCTION convertir_monnaie(montant, devise_source, devise_cible)
    ASSIGNE taux_source = APPELLE taux_vers_euro(devise_source)
    ASSIGNE taux_cible = APPELLE taux_vers_euro(devise_cible)

    ASSIGNE montant_euros = montant / taux_depart
    ASSIGNE montant_final = montant_euros * taux_arrivee

    RETOURNE montant_final
FINFONCTION

DEBUT
    ECRIRE "Choisissez la devise de départ (EUR, GBP, USD, JPY)"
    LIRE devise_source

    ECRIRE "Entrez le montant à convertir"
    LIRE montant_depart

    ECRIRE "Choisissez la devise d'arrivée (EUR, GBP, USD, JPY)"
    LIRE devise_cible

    ASSIGNE resultat = APPELLE convertir_monnaie(montant_depart, devise_source, devise_cible)
    ECRIRE "Le montant converti est <resultat>"
FIN
```

### Exercice 7

```
DEBUT
    ASSIGNE compteur_jours = 0
    ASSIGNE continuer = VRAI
    ASSIGNE temp_max = -infini
    ASSIGNE temp_min = infini
    ASSIGNE somme_temp = 0
    ASSIGNE precipitations_globales = 0

    FAIRE
        compteur_jours = compteur_jours + 1
        
        ECRIRE "Température du jour <compteur_jours>"
        LIRE temperature
        
        ECRIRE "Précipitations du jour <compteur_jours>"
        LIRE precipitation

        SI temperature > temp_max
            temp_max = temperature
        FINSI

        SI temperature < temp_min
            temp_min = temperature
        FINSI

        somme_temp = somme_temp + temperature
        precipitations_globales = precipitations_globales + precipitation
        
        ECRIRE "Voulez-vous ajouter un autre jour ?"
        LIRE continuer

    TANTQUE continuer est VRAI
    FINTANTQUE

    ASSIGNE moyenne_temp = somme_temp / compteur_jours

    ECRIRE "Température la plus haute <temp_max> °C"
    ECRIRE "Température la plus basse <temp_min> °C"
    ECRIRE "Température moyenne <moyenne_temp> °C"
    ECRIRE "Précipitations globales <precipitations_globales>mm"
FIN
```
