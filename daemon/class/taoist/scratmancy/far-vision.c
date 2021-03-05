#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
	object newsheet;
	string err;

	if(me->query("class")!="taoist")
		return notify_fail("只有三清宫弟子才可以画符。\n");
		
	if((int)me->query_skill("scratmancy",1) < 35 )
		return notify_fail("天眼符需要35级有效符之术！\n");

	if( sheet->name() != "桃符纸" ) 
		return notify_fail("天眼符要画在桃符纸上！\n");

    if( (int)me->query("mana") < 20 ) 
		return notify_fail("天眼符需要20点法力！\n");
	me->add("mana", -20);
	me->force_status_msg("mana");
	
	sheet->set_amount((int)sheet->query_amount() - 1);
	seteuid( geteuid(me));
	newsheet = new("/obj/item/magic_seal");
	newsheet->set_name(YEL "天眼符" NOR, 
			({ "far-vision sheet", "sheet"}));      
	newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
	newsheet->move(me);
	newsheet->set("burn_person",me);

	me->save();
	message_vision("$N写了一道天眼符。\n" NOR, me);
	return 1;
}

int do_burn(object sheet) { 
	string target;
	object obj;

	if (sheet->query("targetname")=="monster nian")
		return notify_fail("无法利用这道符寻找活动NPC。\n");
	
	if(!(sheet->query("targetname"))) {
		return notify_fail("你想用这道符" NOR "看谁？\n");
	}
	message_vision("$N集中精神，祭起三味真火，唿的一声" + sheet->name() + "着了起来！\n", this_player());
	this_player()->receive_damage("sen", 5);
	target = sheet->query("targetname");
	obj = find_player(target);
	if(!obj) obj = find_real_living(target);
	if(!objectp(obj) || !objectp(environment(obj)) 
			|| sheet->query("burn_person") != this_player()
			|| environment(obj)->query("no_magic")
			|| environment(obj)->is_character() 
			|| userp(obj)) {
		message("vision", "你感到眼睛酸酸的，却什么也没看到！\n", this_player());
	} else {
		message("vision", "在闪烁的火光中，你看到：\n", this_player());
				"/cmds/std/look"->look_room(this_player(), environment(obj));
		message("vision", "你感到脖子发凉，黑暗处好像有双眼睛盯着你！\n", obj);
		message("vision", "你仔细地看了一下四周，却什么也没有！\n", obj);
	}
	return 1;
}


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
