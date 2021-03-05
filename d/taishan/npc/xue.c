#include <ansi.h>
inherit NPC;
void create()
{
        set_name("雪衣人", ({ "xue yiren" }) );
        set("gender", "女性");
		set("age",25);
		set("combat_exp", 1000000);
        set("class","demon");
        
        set("long",	"一个很漂亮的女人，她的来去就像是一阵风，一朵云，一片雪花。\n");
	
		set_skill("demon-steps",100);
		set_skill("demon-strike",100);
		set_skill("move",300);
        set_skill("dodge", 150);
		set_skill("unarmed",100);
		set_skill("parry",100);
	
		map_skill("unarmed","demon-strike");
		map_skill("dodge","demon-steps");
		map_skill("move","demon-steps");
	
        set("chat_chance", 1);
        set("chat_msg", ({
			(: random_move :),
			name()+"笑了笑：丁鹏练的那一刀并不是用来对付你的。\n",
			name()+"道：丁鹏练这一招，为的是对付谢家三少爷。\n"
        }) );
		setup();
        carry_object(__DIR__"obj/ycloth")->wear();
        carry_object(__DIR__"obj/fshoe")->wear();
}
