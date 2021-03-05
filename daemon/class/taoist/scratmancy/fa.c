
#include <ansi.h>

inherit F_CLEAN_UP;


string clr = "碧";


int scribe(object me, object sheet)
{
	object newsheet;
	string err;
	int skill;
	string name;
	int amn,cost;

		if(me->query("class")!="taoist")
			return notify_fail("只有三清宫弟子才可以画符。\n");
		
		skill = me->query_skill("scratmancy",1);
		
		if(skill < 70 )
			return notify_fail("此符至少需要70级三清符术！\n");

		if (skill < 140) {
			name="续法符";
			amn = 200;
			cost = 50;
		} else if (skill < 200) {
			name="续灵符";
			amn = 400;
			cost = 100;
		} else {
			name="续道符";
			amn = 600;
			cost = 150;
		}	
		
		if( sheet->name() != "桃符纸" ) 
				return notify_fail(name+"要画在桃符纸上！\n");

		sheet->set_amount((int)sheet->query_amount() - 1);
		seteuid( geteuid(me));
		newsheet = new("/obj/item/magic_seal");
		newsheet->set_name(CYN +name+ NOR, ({ "tomana sheet" }));      


		newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
		newsheet->move(me);
		newsheet->set("burn_person",me);
		
		newsheet->set("s_name",name);
		newsheet->set("s_amn", amn);
		newsheet->set("s_cost",cost);
		
		me->save();
		message_vision("$N画了一道"CYN+name+ NOR"。\n" NOR, me);
		return 1;
}

int do_burn(object sheet)
{ 
	string target;
	object obj,me=this_player();
	int ap,dp;

	string name;
	int amn, cost;
	name = sheet->query("s_name");
	amn = sheet->query("s_amn");
	cost = sheet->query("s_cost");
	
	if (!me->is_fighting())
		return notify_fail(CYN+name+ NOR "只能在战斗中使用。\n");

	if (me->query("mana") < cost)
		return notify_fail("焚烧" CYN+name+  NOR "需要至少"+cost+"法力。\n");
	me->add("mana",-cost);
	me->force_status_msg("mana");
	
    if( sheet->query("burn_person")!=me )
	{
		message("vision", "但是什麽也没有发生。\n", environment(me));
		return 1;
	}
	
	obj=me->select_opponent();
	if (!obj)	
		return notify_fail(CYN+name+ NOR "只能在战斗中使用。\n");
		
	message_vision(CYN"\n$N焚起一张"+name+" ，一道淡淡的烟气袅袅升起，在空中盘旋一周，向$n直射而去！\n\n"NOR, me,obj);

	ap = me->query_skill("scratching");
	ap = ( ap * ap / 50 ) * (int)me->query("sen") ;
	dp = obj->query("combat_exp");

	if( random(ap + dp) > dp )
	{
		message_vision(WHT"烟气穿过$n身体，转为浅浅的"+clr+"色，飞回$N手中凝结成形。\n\n"NOR, me,obj);
		if (userp(obj))
		{
			obj->add("mana",-amn/2);
			if (obj->query("mana")<0)
				obj->set("mana",0);
		}
		obj->set_temp("damaged_during_attack", 1);
		COMBAT_D->report_status(obj);
		if (!present("mana sheet",me))
		{
			seteuid( geteuid(me));
			obj = new("/obj/item/magic_seal");
			obj->set_name(YEL+name+  NOR, ({ "mana sheet"}));  
			
			obj->set("desc_ext","恢复"+amn+"点法力");

			obj->set("burn_func", (: call_other, __FILE__, "do_heal" :));
			obj->move(me);
			obj->set("burn_person",me);
			obj->set("lore",1);
			obj->set("s_name",name);
			obj->set("s_amn", amn);
		}
		else
			message_vision(HIB"忽然浓烟升起，符咒竟自化飞灰。\n\n"NOR, me,obj);
	}
	else
		message_vision(YEL"但是被$n躲开了。\n\n"NOR, me,obj);
	me->perform_busy(2);	
	return 1;
}

int do_heal(object sheet)
{ 
	string target;
	object obj,me=this_player();
	int ap,dp;

	string name;
	int amn;
	name = sheet->query("s_name");
	amn  = sheet->query("s_amn");
		
	if (sheet->query("burn_person")!= me) {
		message_vision(CYN"$N焚起一张"+name+ "，一道淡"+clr+"色的烟气袅袅升起，很快就消失了。\n\n"NOR, me);
		return 1;
	}
	
	message_vision(CYN"\n$N焚起一张"+name+ "，一道淡"+clr+"色的烟气袅袅升起，在$N身边环绕不去。\n\n"NOR, me);
	me->add("mana",amn,me);
	if (me->query("mana") > me->query("max_mana")*2)
		me->set("mana",me->query("max_mana")*2);
	me->force_status_msg("mana");
	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/


/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
