/**********************************************************************
* Baseado no código disponibilizado em
*  Application Note: "Object-Oriented Programming in C"
* https://www.state-machine.com/doc/AN_OOP_in_C.pdf
*
* Aqui se implementa o número do tipo "racional"
*
* numero.h definiu a interface do "número_t virtual"
* que é usada aqui
* ********************************************************************/
#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "meuracional.h"

static  Numero_pt copia_ (Numero_t const * const  me);

static  Numero_pt atribui_ (Numero_t const * const  me,
							         Numero_t       * const  outro) ;

static  Numero_pt soma_  (Numero_t const * const  me,
								   Numero_t const * const  outro,
							       Numero_t       * const  res);

static  Numero_pt subt_  (	Numero_t const * const  me,
									Numero_t const * const  outro,
									Numero_t       * const  res);

static  Numero_pt mult_  ( Numero_t const * const  me,
									Numero_t const * const  outro,
									Numero_t       * const  res);

static  Numero_pt divd_  ( Numero_t const * const  me,
									Numero_t const * const  outro,
									Numero_t       * const  res);

static  Numero_pt ac_soma_ (Numero_t       * const  me,
									 Numero_t const * const  outro);

static  Numero_pt ac_subt_ (Numero_t       * const  me,
									 Numero_t const * const  outro);

static  Numero_pt ac_mult_ (Numero_t       * const  me,
									 Numero_t const * const  outro);

static  Numero_pt ac_divd_ (Numero_t       * const  me,
									 Numero_t const * const  outro);

static  int	compara_ 	(Numero_t const * const  me,
							 Numero_t const * const  outro);

static  char * imprime_  (Numero_t const * const  me);

static  void destroi_ (Numero_t   *   me);



/*---------------------------------------------------------------------*
 * IMPLEMENTAÇÃO DA INTERFACE PÚBLICA das funções virtuais de MeuDouble*
 * -------------------------------------------------------------------*/
static  MeuRacional_pt Copia_ (MeuRacional_t const * const  me);

static  MeuRacional_pt Atribui_ (MeuRacional_t const * const  me,
							     MeuRacional_t       * const  outro) ;

static  MeuRacional_pt Soma_  (MeuRacional_t const * const  me,
							   MeuRacional_t const * const  outro,
							   MeuRacional_t       * const  res);

static  MeuRacional_pt Subt_  (MeuRacional_t const * const  me,
							   MeuRacional_t const * const  outro,
							   MeuRacional_t       * const  res);

static  MeuRacional_pt Mult_  ( MeuRacional_t const * const  me,
								MeuRacional_t const * const  outro,
								MeuRacional_t       * const  res);

static  MeuRacional_pt Divd_  ( MeuRacional_t const * const  me,
								MeuRacional_t const * const  outro,
								MeuRacional_t       * const  res);

static  MeuRacional_pt Ac_Soma_ (MeuRacional_t       * const  me,
								 MeuRacional_t const * const  outro);

static  MeuRacional_pt Ac_Subt_ (MeuRacional_t       * const  me,
								 MeuRacional_t const * const  outro);

static  MeuRacional_pt Ac_Mult_ (MeuRacional_t       * const  me,
								 MeuRacional_t const * const  outro);

static  MeuRacional_pt Ac_Divd_ (MeuRacional_t       * const  me,
								 MeuRacional_t const * const  outro);

static  int	Compara_ 	    (MeuRacional_t const * const  me,
							 MeuRacional_t const * const  outro);

static  char *      Imprime_  (MeuRacional_t const * const  me);

static  void        Destroi_ (MeuRacional_t  *   me);

/* ------------------------------------------------------- *
 * funções que são típicas do numero racional, mas não são *
 * funcoes da classe virtual básica número                 *
 * protótipos das funçoes get e set, por exemplo           *
 *---------------------------------------------------------*/
static 	void     Get_ (MeuRacional_t  const * const me,
					   long int * valorNum,
					   long int * valorDen);

static 	void     Set_ (MeuRacional_t   * const me,
					   long int valorNum,
					   long int valorDen);

static 	long int   GetNum_ (MeuRacional_t  const * const me);

static 	void     SetNum_ (MeuRacional_t   * const me,
					     long int valorNum);

static 	long int   GetDen_ (MeuRacional_t  const * const me);

static 	void     SetDen_ (MeuRacional_t   * const me,
					       long int valorDen);

static long double  Modulo_ (MeuRacional_t   const * const me);

static long int Potencia_ (MeuRacional_t const * const me, int expoente);

static long double Raizqqr_ (MeuRacional_t const * const me, double expo);

static int Int_proximo_ (MeuRacional_t const * const me);

static MeuRacional_pt (MeuRacional_t const * const me, MeuRacional * const temp);


 /*---------------------------------------------*
 * implementação do construtor                  *
 * ---------------------------------------------*/
MeuRacional_pt Racional_constroi (MeuRacional_pt  me,
							      long int valorNum,
							      long int valorDen);
{

    static struct NumeroVtbl const vtbl = {
        &copia_,
        &atribui_,
        &soma_,
        &subt_,
        &mult_,
        &divd_,
        &ac_soma_,
        &ac_subt_,
        &ac_mult_,
        &ac_divd_,
        &compara_,
        &imprime_,
        &destroi_
     };

         me = (MeuRacional_pt) Num_constroi ((Numero_pt) me);
                        /*constroi o Numero_t  */
                        /* no início de MeuRacional_t  */

         me->super.metodo = &vtbl;
            /* metodo aponta para vtbl de MeuRacional_t */
            /* as operações do "numero", a partir de agora,     */
            /* são as operações sobre long int                   */

     static struct MeuRacional_Interface_st const interface = {
        &Copia_,
        &Atribui_,
        &Soma_,
        &Subt_,
        &Mult_,
        &Divd_,
        &Ac_Soma_,
        &Ac_Subt_,
        &Ac_Mult_,
        &Ac_Divd_,
        &Compara_,
        &Imprime_,
        &Destroi_,
        &Get_,
        &Set_,
        &GetNum_,
        &SetNum_,
        &GetDen_,
        &SetDen_,
        &Modulo_,
        &Potencia_,
        &Raizqqr_,
        &Int_proximo_,
        &Inverso_,
     };

     me->Metodo = &interface;
            /* metodo aponta para vtbl de MeuRacional_t */
            /* as operações do "numero", a partir de agora,     */
            /* são as operações sobre long int                    */

	me->valor = (long int *) malloc (2*sizeof(long int));
	if (me->valor == NULL)
	{	/*erro!!! não conseguiu alocar */
	    printf ("Erro na alocação de memória em Num_Constroi");
	    printf ("Nao alocou o valor long int");
	    exit (1);
	}

	/* copia o double passado como parâmetro */
    /* no endereco de memoria recém alocado  */
     me->valor[0] = valorNum;
     me->valor[1] = valorDen;

     return (me);

}


 /*---------------------------------------------*
 * implementação do set e get                   *
 * ---------------------------------------------*/
static inline
void Get_ (MeuRacional_t  const * const me,
			long int               * ptNum,
	        long int 				 * ptDen)

{
	 *ptNum = (me->valor[0]);
	 *ptDen = (me->valor[1]);

}


static inline
void Set_ (MeuRacional_t       * const me,
			long int                valorNum,
	        long int				valorDen)
{
	me->valor[0] = valorNum;
	me->valor[1] = valorDen;

}

static inline
long int GetNum_ (MeuRacional_t  const * const me)
{
	 return ( (me->valor[0]));

}


static inline
void SetNum_ (MeuRacional_t     * const me,
			  long int            valorNum)
{
	me->valor[0] = valorNum;

}

static inline
long int  GetDen_ (MeuRacional_t  const * const me)
{
	 return (me->valor[1]);
}


static inline
void SetDen_ (MeuRacional_t       * const me,
               long int             valorDen)
{
	me->valor[1] = valorDen;
}

static
long double  Modulo_ (MeuRacional_t  const * const me)
{
   return((long double) GetNum_(me)/(long double) GetDen_(me));
}

static
long double Potencia_ (MeuRacional_t const * const me, int expoente);
{
    return ((long double) pow(Modulo_(me), expoente));
}

static
long double Raizqqr_ (MeuRacional_t const * const me, double expo);
{
    return ((long double) pow(Modulo_(me),1.0/ expo));
}

static
int Int_proximo_ (MeuRacional_t const * const me);
{
    long double res = (long double)Modulo_(me) - (long int)Modulo_me;
    if (res >= 0.5)
        return ((long int) Modulo_(me) + 1);
    else if (res < 0.5 || res = 0)
        return ((long int) Modulo_(me));
}

static
MeuRacional_pt Inverso_ (MeuRacional_t const * const me, MeuRacional_t * const temp);
{
    GetNum_(temp) = GetDen_(me);
    GetDen_(temp) = GetNum_(me);

    return ((MeuRacional_pt) temp);
}
/*------------------------------------------------------*
 * IMPLEMENTAÇÃO DAS FUNÇÕES VIRTUAIS           *
 * -----------------------------------------------------*/

static inline
MeuRacional_pt Copia_ (MeuRacional_t const * const  me)
{
	return ( (MeuRacional_pt)
	          copia_ ((Numero_pt) me));
}

 static
 Numero_pt copia_ (Numero_t const * const  me)
{
	assert (me != NULL);
	Numero_pt outro = NULL;
	outro = (Numero_pt) Racional_constroi
							((MeuRacional_pt) outro,
							  GetNum_((MeuRacional_pt) me),
							  GetDen_((MeuRacional_pt) me));
	return outro;
}

/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Atribui_(MeuRacional_t const * const me,
					    MeuRacional_t       * const outro )
{
	return ( (MeuRacional_pt)
	          atribui_ ((Numero_pt) me,
                        (Numero_pt) outro));
}

static
 Numero_pt atribui_ (Numero_t const * const  me,
                     Numero_t       * const  outro)
 {
	 Set_( (MeuRacional_pt) outro,
	       GetNum_((MeuRacional_pt) me),
	       GetDen_ ((MeuRacional_pt) me) );

	 return (Numero_pt) outro;
 }
/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Soma_  ( MeuRacional_t const * const  me,
						   MeuRacional_t const * const  outro,
						   MeuRacional_t       * const  res)
{
	return ( (MeuRacional_pt)
	          soma_ ((Numero_pt) me,
					 (Numero_pt) outro,
					 (Numero_pt) res));
}

static  Numero_pt soma_  ( Numero_t const * const  me,
								Numero_t const * const  outro,
								Numero_t       * const  res)
{
	Set_((MeuRacional_pt) res,
				(GetNum_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro) +
                GetNum_((MeuRacional_pt) outro) * GetDen_((MeuRacional_pt) me)),
                GetDen_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro))

	return (Numero_pt) res;
}

/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Subt_  (      MeuRacional_t const * const  me,
						   MeuRacional_t const * const  outro,
						   MeuRacional_t       * const  res)
{
	return ( (MeuRacional_pt)
	          subt_ ((Numero_pt) me,
                     (Numero_pt) outro,
                     (Numero_pt) res));
}
static  Numero_pt subt_  (	Numero_t const * const  me,
								    Numero_t const * const  outro,
								    Numero_t       * const  res)
{
	Set_((MeuRacional_pt) res,
				(GetNum_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro) -
                GetNum_((MeuRacional_pt) outro) * GetDen_((MeuRacional_pt) me)),
                GetDen_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro))

		return (Numero_pt) res;
}

/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Mult_  ( MeuRacional_t const * const  me,
						   MeuRacional_t const * const  outro,
						   MeuRacional_t       * const  res)
{
	return ( (MeuRacional_pt)
	          mult_ ((Numero_pt) me,
                     (Numero_pt) outro,
                     (Numero_pt) res));
}

static  Numero_pt mult_  ( Numero_t const * const  me,
								Numero_t const * const  outro,
								Numero_t       * const  res)
{
    Set_((MeuRacional_pt) res,
                 GetNum_((MeuRacional_pt) me) * GetNum_((MeuRacional_pt) outro),
                 GetDen_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro))


	 return ( (Numero_pt) res);
}

/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Divd_  ( MeuRacional_t const * const  me,
						   MeuRacional_t const * const  outro,
						   MeuRacional_t       * const  res)
{
	return ( (MeuRacional_pt)
	          divd_ ((Numero_pt) me,
                     (Numero_pt) outro,
                     (Numero_pt) res));
}

static  Numero_pt divd_  (	Numero_t const * const  me,
								Numero_t const * const  outro,
								Numero_t       * const  res)
{
    Set_((MeuRacional_pt) res,
                  GetNum_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro),
                  GetDen_((MeuRacional_pt) me) * GetNum_((MeuRacional_pt) outro))

	 return ( (Numero_pt) res);
}

/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Ac_Soma_  ( MeuRacional_t  * const  me,
                        MeuRacional_t const * const  outro)
{
	return ( (MeuRacional_pt)
	          ac_soma_ ((Numero_pt) me,
                        (Numero_pt) outro));
}

static  Numero_pt ac_soma_  (Numero_t       * const  me,
                             Numero_t const * const  outro)
{
	Set_((MeuRacional_pt) me,
				(GetNum_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro) +
                 GetNum_((MeuRacional_pt) outro) * GetDen_((MeuRacional_pt) me)),
                 GetDen_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro))

	return ((Numero_pt) me);
}

/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Ac_Subt_  ( MeuRacional_t  * const  me,
						  MeuRacional_t const * const  outro)
{
    return ( (MeuRacional_pt)
              ac_subt_ ((Numero_pt) me,
                        (Numero_pt) outro));
}


static  Numero_pt ac_subt_  (Numero_t       * const  me,
                             Numero_t const * const  outro)
{
	Set_((MeuRacional_pt) me,
				(GetNum_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro) -
                 GetNum_((MeuRacional_pt) outro) * GetDen_((MeuRacional_pt) me)),
                 GetDen_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro))


	return (Numero_pt) me;
}

/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Ac_Mult_  ( MeuRacional_t  * const  me,
						   MeuRacional_t const * const  outro)
{
	return ( (MeuRacional_pt)
	          ac_mult_ ((Numero_pt) me,
                        (Numero_pt) outro));
}


static  Numero_pt ac_mult_  (Numero_t       * const  me,
                             Numero_t const * const  outro)
{
    Set_((MeuRacional_pt) me,
               GetNum_((MeuRacional_pt) me) * GetNum_((MeuRacional_pt) outro),
               GetDen_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro))

	 return ((Numero_pt) me);
}

/*-----------------------------------------------------------------*/
static inline
MeuRacional_pt Ac_Divd_  ( MeuRacional_t  * const  me,
						   MeuRacional_t const * const  outro)
{
	return ( (MeuRacional_pt)
	          ac_divd_ ((Numero_pt) me,
                        (Numero_pt) outro));
}


static  Numero_pt ac_divd_  (Numero_t       * const  me,
                             Numero_t const * const  outro)
{
    Set_((MeuRacional_pt) me,
               GetNum_((MeuRacional_pt) me) * GetDen_((MeuRacional_pt) outro),
               GetDen_((MeuRacional_pt) me) * GetNum_((MeuRacional_pt) outro))

	 return ( (Numero_pt) me);
}

/*-----------------------------------------------------------------*/
static inline
int Compara_  ( MeuRacional_t const * const  me,
				MeuRacional_t const * const  outro)
{
	return ( compara_ ((Numero_pt) me,
                       (Numero_pt) outro));
}

static  int	compara_ 	(Numero_t const * const  me,
                         Numero_t const * const  outro)
{
    if( Modulo_((MeuRacional_pt)me) > Modulo_((MeuRacional_pt)outro) )
	{ return (1);}
	else if( Modulo_((MeuRacional_pt)me) < Modulo_((MeuRacional_pt)outro) )
	{ return (-1);}
	else if( Modulo_((MeuRacional_pt)me) == Modulo_((MeuRacional_pt)outro) )
	{ return (0); }


	return(0);
}

/*-----------------------------------------------------------------*/
static inline
char * Imprime_  ( MeuRacional_t const * const  me)
{
	return ( imprime_ ((Numero_pt) me));
}
static  char * imprime_  (Numero_t const * const  me)
{
    static char buffer[50];

	sprintf(buffer, "%d/%d", GetNum_((MeuRacional_pt) me),(GetDen_((MeuRacional_pt) me)) );

	return buffer;

}


 /*---------------------------------------------*
 * implementação do destrutor                   *
 * ---------------------------------------------*/
 /*-----------------------------------------------------------------*/
static inline
void Destroi_  ( MeuRacional_t  *   me)
{
	  destroi_ ((Numero_t *)  me);
}
static void destroi_ (Numero_t *  me)
{
	/* primeiro destroi o valor double */
	free (((MeuRacional_pt) me)->valor);
	/*... e só agora destroi-se o número virtual da classe base */
	free ((Numero_t *) me);
}
