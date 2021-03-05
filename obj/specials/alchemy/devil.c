// devil.c

#include <ansi.h>

inherit NPC;
void emerge(object, int);
void generate_name();
void create()
{	
	generate_name();
        set("race", "野兽");
        set("age", 10 + random(20));
        set("long", "一只稀奇古怪的异形，看不出来是什么东西。\n");
        set("max_kee", 800);
        set("max_qin", 800);
        set("max_sen", 200);
		set("str", 20 + random(40));
		set("cor",50);
        set("limbs", ({ "头部", "身体", "尾巴","爪子" }) );
        set("verbs", ({ "bite","claw"}) );
                set("attitude","heroism");
                
        set("chat_combat_chance", 30);
        set("chat_combat_msg", ({
                this_object()->name()+"唧唧怪叫着一些你听不懂的话。\n",
        }) );


	set("combat_exp", 1100000);
	set_skill("unarmed", 30);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("move", 50);

	setup();


}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	
	message("vision",
         name() + "唧唧唧一阵乱叫，钻到什么角落里不见了。\n" , environment(),
		this_object() );
  
	destruct(this_object());
}

void emerge(object who, int level)
{
	set_skill("unarmed", 100 + random(level));
	set_skill("parry", 100 + random(level));
	set_skill("dodge", 100 + random(level));
	set_skill("move", 100 + random(level));
	set("combat_exp", 10000 + random(level*level*level));
		
	kill_ob(who);
	who->kill_ob(this_object());
	set("possessed",who);
}

void generate_name(){
	string *color = ({HIB, CYN, BLU, WHT, YEL, RED, HIM});
	string *number = ({"三", "七", "五","破",HIW"白", "九", "十三", "独", "无"});
	string *part = ({"尾", "头", "眼","足","翅","命","面", "爪"});
	string *race = ({"怪蛙", "蛇","龙虾","乌鸦", "蜥蜴", "蝎子", "螃蟹", "老鼠","次郎",
	 "壁虎", "拉登","太郎","蝴蝶","狐狸","菜皮","狼","刺猬","老猫"});
	set_name( (color[random(sizeof(color))])+(number[random(sizeof(number))]) 
		   + (part[random(sizeof(part))])
		   + (race[random(sizeof(race))])
		   + NOR, ({ "alchemy devil", "devil" }) );
	
}
