inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(WHT"年糕"NOR , ({ "nian gao" }) );
	set_weight(6);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", YEL"黏性大的米或米粉蒸成的糕，是农历年的应时食品。\n"NOR);
        	set("unit", "片");
        	set("lore",1);
        	set("value", 2);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	mapping buff1,buff2,buff3;
	object me = this_player();
	string bufftype,type,name,msg;
	int amount,n,n2,n3;
	
  string *list = ({ "apply/attack" , "apply/dodge" , "apply/parry" , "apply/iron-cloth" , "apply/armor" , "apply/damage" });
  string *typelist = ({ "attackup" , "dodgeup" , "parryup" , "iron-clothup" , "armorup" , "damageup" });
  int  *list_m = ({ 120, 120, 120, 120 ,120 ,60 });
  string *list_c_n = ( {"斗士","土灵","卸甲","钢盾","金甲神","破坏神" });
  string *list_c = ( {"攻击","闪避","拆招","硬功","护甲","伤害" });

	msg = RED "$N顿时觉得浑身暖意：过节真幸福！\n"NOR;
	
	if (ANNIE_D->check_buff(me,"attackup") || ANNIE_D->check_buff(me,"dodgeup") || ANNIE_D->check_buff(me,"parryup") || ANNIE_D->check_buff(me,"iron-clothup") || ANNIE_D->check_buff(me,"armorup") || ANNIE_D->check_buff(me,"damageup"))	// it won't show up..just eat it.
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
		"name":	"年糕·"+name,
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
		"name":	"年糕·"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":"",
	]);
  ANNIE_D->buffup(buff2);      
  tell_object(me,CYN"（你的"+ list_c[n] + "提高了"+ amount + "点）\n"NOR);

  n3=n;
  
  while(n3==n || n2==n) {
  	n = random(sizeof(list));
  }

  type = typelist[n];
  bufftype = list[n];
  amount = list_m[n];
  name = list_c_n[n];


  buff3 =
	([
		"caster":me,
		"who": 	me,
		"type":	type,
		"att":	"bless",
		"name":	"年糕·"+name,
		"buff1":bufftype,
		"buff1_c":amount,
		"time":  10800 ,
		"buff_msg":"",
	]);
  ANNIE_D->buffup(buff3);      
  tell_object(me,CYN"（你的"+ list_c[n] + "提高了"+ amount + "点）\n"NOR);


  destruct(this_object());
 	return 1;
}
