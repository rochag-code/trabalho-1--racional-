#ifndef MEURACIONAL_H_INCLUDED
#define MEURACIONAL_H_INCLUDED
#include "numero.h"

struct MeuRacional_Interface_st;

struct MeuRacional_st{
    struct Numero_st super;

    struct MeuRacional_Interface_st const * Metodo;

    long int *valor;
};
typedef struct MeuRacional_st *MeuRacional_pt;
typedef struct MeuRacional_st MeuRacional_t;

typedef struct MeuRacional_Interface_st *MeuRacional_Interface_pt;

MeuRacional_pt Racional_constroi(MeuRacional_pt me, long int valorNum, long int valorDen);

struct MeuRacional_Interface_st{

    MeuRacional_pt (*copia)	(MeuRacional_t const * const me);

    MeuRacional_pt (*atribui)	(MeuRacional_t const * const  me,
                                 MeuRacional_t       * const  outro);

    MeuRacional_pt (*soma)	(MeuRacional_t const * const  me,
							 MeuRacional_t const * const  outro,
							 MeuRacional_t       * const res);

    MeuRacional_pt (*subt)	(MeuRacional_t const * const  me,
							 MeuRacional_t const * const  outro,
							 MeuRacional_t       * const res);

    MeuRacional_pt (*mult)	(MeuRacional_t const * const  me,
							MeuRacional_t const * const  outro,
							MeuRacional_t        * const res);

    MeuRacional_pt (*divd)	(MeuRacional_t const * const  me,
							 MeuRacional_t const * const  outro,
							 MeuRacional_t       * const res);

    MeuRacional_pt (*ac_soma)	(MeuRacional_t       * const  me,
							     MeuRacional_t const * const  outro);

    MeuRacional_pt (*ac_subt)	(MeuRacional_t       * const  me,
							     MeuRacional_t const * const outro);

    MeuRacional_pt (*ac_mult)	(MeuRacional_t       * const  me,
							     MeuRacional_t const * const outro);

    MeuRacional_pt (*ac_divd)	(MeuRacional_t        * const  me,
							     MeuRacional_t const * const outro);

    long int			(*compara)	(MeuRacional_t const * const  me,
							 MeuRacional_t const * const  outro);

    char *      (*imprime)  (MeuRacional_t const * const  me);

    void        (*destroi)  (MeuRacional_t       *        me);

/*---------------------------------------------------------------------------------*/

    void        (*get    )  (MeuRacional_t const * const me,
                             long int            * ptNum,
                             long int            * ptDen);

	void   	    (*set     ) (MeuRacional_t        * const me,
	                          long int             valorNum,
	                          long int 		       valorDen);


	long int       (*getNum ) (MeuRacional_t  const * const me);


	void   	     (*setNum ) (MeuRacional_t        * const me,
	                          long int               valorNum);

    long int       (*getDen ) (MeuRacional_t  const * const me);


	void   	     (*setDen ) (MeuRacional_t        * const me,
	                          long int               valorDen);

    long double  (*modulo) (MeuRacional_t   const * const me);

    long int (*potencia) (MeuRacional_t const * const me, int expoente);

    long double (*raizqqr) (MeuRacional_t * const me, double expo);

    MeuRacional_pt (*inverso) (MeuRacional_t const * const me, MeuRacional_t * const temp);

    int (*int_proximo) (MeuRacional_t * const me);


};

#endif // MEURACIONAL_H_INCLUDED
