/*Este programa le pide al usuario 4 puntos con componentes (x,y) para formar dos rectas y mira si estas dos rectas
son paralelas, perpendiculares y que muestre el punto de intersección donde se unen las dos rectas.

 Autores:Leidy Ximena Garzón y Sebastian Babativa Veloza
 Versión:1.0
 */

#include <iostream>

using namespace std;
class puntos{ //clase padre pide datos

protected:
 float x1,x2,x3,x4; //declaraciones
 float y1,y2,y3,y4;//declaraciones
public:
  void pedir_punt()
  {
    cout<<"\n\n Este programa mira si dos rectas son paralelas, perpendiculares o muestra el punto de interseccion entre ellas\n";
    cout<<"\n\n Para formar la primera recta necesitamos dos puntos\n";
    cout<<"\n\nLa forma de ingresar los puntos es primero x1 y luego y1 para que el punto quede de la siguiente manera(x1,y1)\n\n";
    cout<<"\n\n Ingrese la primera componente del primer punto x1:\n"; cin >>x1;
    cout<<"\n\n Ingrese la primera componente del primer punto y1:\n"; cin >>y1;
    cout<<"\n\nLa forma de ingresar los puntos es primero x2 y luego y2 para que el punto quede de la siguiente manera(x2,y2)\n\n";
    cout<<"\n\n Ingrese la primera componente del primer punto x2:\n"; cin >>x2;
    cout<<"\n\n Ingrese la primera componente del primer punto y2:\n"; cin >>y2;
    cout<<"\n\n Para formar la segunda recta necesitamos dos puntos\n";
    cout<<"\n\nLa forma de ingresar los puntos es primero x3 y luego y3 para que el punto quede de la siguiente manera(x3,y3)\n\n";
    cout<<"\n\n Ingrese la primera componente del primer punto x3:\n"; cin >>x3;
    cout<<"\n\n Ingrese la primera componente del primer punto y3:\n"; cin >>y3;
    cout<<"\n\nLa forma de ingresar los puntos es primero x4 y luego y4 para que el punto quede de la siguiente manera(x4,y4)\n\n";
    cout<<"\n\n Ingrese la primera componente del primer punto x4:\n"; cin >>x4;
    cout<<"\n\n Ingrese la primera componente del primer punto y4:\n"; cin >>y4;

  }
};
//heriencia
class recta:public puntos{// clase hijo
private:
  float m1,m2,m3;
  float cx,cy;
  float b1,b2;
public:
  void pendiente()// hallar pendiente
{


    if(x1!=x2)// para no generar indeterminación
      m1=(y2-y1)/(x2-x1);
    else
	  {
      m1=0;
	  }
        if(x3!=x4)// para no generar indeterminación
	       m2=(y4-y3)/(x4-x3);
        else
		    {
         m2=0;
		    }
}

  void interseccion_y()//hallar punto de intersección
  {
    b1=y1-(m1*x1);
    b2=y3-(m2*x3);

  }
  void mostrar_rectas()
  {
  cout<<"\nLas ecuaciones de las rectas son:: "<<endl<<endl;
      cout<<"y="<<m1;
        if(b1<0)
		      cout<<"x "<<b1<<endl<<endl;
      else
          cout<<"x +"<<b1<<endl<<endl;

		cout<<"y="<<m2;
          if(b2<0)
		         cout<<"x "<<b2<<endl<<endl;
	        else
            cout<<"x +"<<b2<<endl<<endl;
  }



  void relacion_rect(recta);//comparación pendientes
};
void recta:: relacion_rect(recta rectas)//utilizando el objeto como argumento
{
  if(rectas.m1==rectas.m2 )//comparación de pendientes para determinar si son paralelas
  	{
  		cout<<"Las rectas son Paralelas"<<endl;

  	}

  	rectas.m3=rectas.m1*(-1);

  	if(rectas.m3==rectas.m2)//comparación de pendientes para determinar si son perpendiculares
  	{
  		cout<<"Las rectas son Perpendiculares"<<endl;
  	}
  	rectas.cx=(rectas.b2-rectas.b1)/(rectas.m1-rectas.m2);//hallar punto de interseccion entre ellas
  	rectas.cy=rectas.m1*rectas.cx+rectas.b1;

  	if(rectas.m1!=rectas.m2 && rectas.m3!=rectas.m2)// ver el punto de intersección si no son ni paralelas ni perpendiculares
  	{

  		cout<<"Las rectas se intersectan en : ("<<rectas.cx;
  		cout<<","<<rectas.cy;
  		cout<<")"<<endl;

  	}
}
 int main()
 {
//creación de objetos
recta rectas;
recta operacion;

  rectas.pedir_punt();
  rectas.pendiente();
  rectas.interseccion_y();
  rectas.mostrar_rectas();
  operacion.relacion_rect(rectas);

return 0;
 }
