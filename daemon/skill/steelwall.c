// 这个skill是给wall用的，不要给一般npc

inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","铜墙铁壁");
	set("type","iron-cloth");
	set("skill_class","npc");
	set("difficulty",200);
	set("ic_effect",100);
	set("usage/iron-cloth",1);
	set("bounce_ratio",10);
	set("effective_level",100);
        set("difficutly", 100); 
                set("absorb_msg", ({
                "$n上下泛起一层隐约的淡金色的光辉，宏如泰山，坚如磐石。\n",
                "$N只觉击$n如击铜铁，坚硬无比，刀枪难伤。\n",
        }) );

}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


