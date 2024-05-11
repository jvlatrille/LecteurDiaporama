#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include <vector>

class imageDansDiaporama;
class Modele : public QObject
{
    Q_OBJECT
private:
    std::string m_titre;
    unsigned int m_vitesseDefilement;
    unsigned int m_posImageCourante;
    std::vector<imageDansDiaporama> m_localisationImages;
public:
    explicit Modele(QObject *parent = nullptr);
    std::string getTitre() const;
    unsigned int getVitesseDefilement() const;
    unsigned int getNombreImages() const;
    unsigned int getPosImageCourante() const;

    void setTitre(const std::string&);
    void setVitesseDefilement(unsigned int);
    void setLocalisationImages(const std::vector<imageDansDiaporama>&);
    void setPosImageCourante(unsigned int);

    void avancer();
    void reculer();
    void triCroissantRang();
};

#endif // MODELE_H
