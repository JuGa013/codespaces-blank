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

    aujourdhui = APPELLE DATE()

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
