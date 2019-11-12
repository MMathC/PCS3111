#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H


class CompeticaoSimples
{
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m));
        virtual ~CompeticaoSimples();

        void imprimir();
        Modalidade* getModalidade();

    private:

};

#endif // COMPETICAOSIMPLES_H
