inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(YEL"春卷"NOR , ({ "chun juan" }) );
	set_weight(6);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", YEL"烙熟的圆形薄面皮卷裹馅心，成长条形，然后下油锅炸至金黄色浮起而成。\n"NOR);
        	set("unit", "只");
        	set("lore",1);
        	set("value", 1);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	mapping buff1,buff2;
	object me = this_player();
	string bufftype,type,name,msg;
	int amount,n,n2;
	
  string *list = ({ "apply/karma","apply/composure","apply/agility","apply/strength" });
  string *typelist = ({ "karup" , "cpsup" , "agiup" , "strup" });
  int  *list_m = ({ 10, 10, 10, 10 });
  string *list_c = ( {"运气","定力","速度","力量" });
  string *list_c_n = ( {"猪","蛇","狼","熊" });

	msg = HIY "$N顿时觉得浑身暖意：过节真幸福！\n"NOR;
	
	if (ANNIE_D->check_buff(me,"karup") || ANNIE_D->check_buff(me,"cpsup") || ANNIE_D->check_buff(me,"agiup") || ANNIE_D->check_buff(me,"strup"))	// it won't show up..just eat it.
		return notify_fail("美味依存。\n"); 
	
  n = random(sizeof(list));
  type = typelist[n];
  bufftype = list[n];
  amount = list_m[n];
  name = list_c_n[n];
  
	buff1 =
	([
		"caster":me,
		"who": 	me,
		"type":	type,
		"att":	"bless",
		"name":	"春卷·"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":msg,
		//"disa_msg": "",
		//"special_func":1,
	]);
  ANNIE_D->buffup(buff1);      
  tell_object(me,CYN"（你的"+ list_c[n] + "提高了"+ amount + "点）\n"NOR);
    
  n2=n;
  
  while(n2==n) {
  	n = random(sizeof(list));
  }

  type = typelist[n];
  bufftype = list[n];
  amount = list_m[n];
  name = list_c_n[n];


  buff2 =
	([
		"caster":me,
		"who": 	me,
		"type":	type,
		"att":	"bless",
		"name":	"春卷·"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":"",
	]);
  ANNIE_D->buffup(buff2);      
  tell_object(me,CYN"（你的"+ list_c[n] + "提高了"+ amount + "点）\n"NOR);

  destruct(this_object());
 	return 1;
}
