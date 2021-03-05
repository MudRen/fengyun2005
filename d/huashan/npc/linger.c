#include <ansi.h>
inherit NPC;
int leave();

void create()
{
    	set_name("小铃儿", ({ "xiao linger", "linger" }));
    	set("long", "她身材娇小，漆黑的长发挽成一对垂髻，闪亮著的大眼中充满好奇。\n" );
	set("title", "华山派 第十七代弟子");
 	set("gender", "女性");
	set("age", 13);
	set("per", 27);
	set("agi", 20);
	set("class","huashan");
	set("combat_exp", 280000+random(50000));
	set("attitude", "friendly");

	set("chat_chance", 3);
	set("chat_msg", ({
	 	"小铃儿小声说：我师傅晚上练功夫，一把就抓进树干了耶。 \n",
		"小铃儿自言自语道：华真真师姐好像在教师傅功夫，真是奇怪呀。\n", 
		"小铃儿道：附近那个山洞里好象有"YEL"鬼"NOR"耶．．．\n", 
	}) );
    		
    	set("inquiry", ([
 	 	"鬼" : (: leave :),
         ]) );

 	set_skill("unarmed", 100);
	set_skill("move", 150);
	set_skill("dodge", 145);
	set_skill("parry", 135);
	set_skill("force", 149);
	set_skill("sword", 130);
	set_skill("qingfeng-sword", 100);
	set_skill("zhaixin-claw",100);
	set_skill("anxiang-steps", 100);
	set_skill("hanmei-force",100);
	
	map_skill("force", "hanmei-force");
        map_skill("parry", "qingfeng-sword");
	map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "anxiang-steps");
        map_skill("unarmed","zhaixin-claw");

	setup();
    	carry_object(__DIR__"obj/gcloth",
    		([ 	"name" 	:	"青衣",
    			"long"	:	"淡青色的小褂。"		])
    		)->wear();
    	carry_object("/obj/weapon/sword_short")->wield();

}


int leave() {
	object who = this_player();

	if (REWARD_D->riddle_check(who,"听琴毛女洞") != 2)
	{
		message_vision(CYN"$N向四面望了望，颤抖着道：我不能说，鬼会吃了我的。\n"NOR, this_object(),this_player());
		return 1;
	}

	REWARD_D->riddle_set(who,"听琴毛女洞",3);
	message_vision(CYN"$N抖了一下，一脸惊慌的对$n说：每到半夜，那里就有弹琴的声音，好可怕．．．\n"NOR, this_object(),this_player());
	return 1;
}