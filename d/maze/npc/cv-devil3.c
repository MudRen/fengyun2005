#include <ansi.h>
inherit MAZE_NPC;

void generate_name();
void create()
{	
		generate_name();
        set("race", "野兽");
        set("age", 10 + random(20));
        set("long", "炼丹不慎跳出来的怪物，不知怎么流落到这里，样子稀奇古怪。\n");
        set("maze","cave");
		set("cor",50);
        set("attitude","aggressive");
                
        set("chat_combat_chance", 30);
        set("chat_combat_msg", ({
//              this_object()->name()+"唧唧怪叫着一些你听不懂的话。\n",
        }) );
	
	set("pursuer",1);
	        
	set("combat_exp", 1200000+random(200000));
	
	set_skill("unarmed",600+random(100));
	set_skill("dodge", 600+random(100));
	set_skill("move", 400+random(100));
	
	setup();
}


void generate_name(){
	string *color = ({HIB, CYN, BLU, WHT, YEL, RED, HIM});
	string *number = ({"三", "七", "五","破",HIW"白", "九", "十三", "独", "无"});
	string *part = ({"尾", "头", "眼","足","翅","命","面", "爪"});
	string *race = ({"怪蛙", "蛇","龙虾","乌鸦", "蜥蜴", "蝎子", "螃蟹", "老鼠","次郎",
	 "壁虎", "拉登","太郎","蝴蝶","狐狸","菜皮","狼","刺猬","老猫"});
	set_name( (color[random(sizeof(color))])+(number[random(sizeof(number))]) 
		   + (part[random(sizeof(part))])
		   + "老"
		   + (race[random(sizeof(race))])
		   + NOR, ({ "alchemy devil", "devil" }) );
	
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}