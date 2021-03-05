
#include <ansi.h>

inherit NPC;
void goto_batdao(object ob);
void create()
{
    	set_name("白菊", ({ "bai ju" }));
    	set("long", "一个十三四岁的小姑娘，大大的眼睛，笑起来还有两个深深的酒窝。\n" );
	set("title", "华山派 第十七代弟子");
 	set("gender", "女性");
	
	set("age", 13);

	set("combat_exp", 400000);
	set("attitude", "friendly");
 	
 	set_skill("unarmed", 100);
	set_skill("move", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("hanmei-force",80);
	set_skill("zhaixin-claw",60);
	set_skill("qingfeng-sword", 100);
	set_skill("anxiang-steps", 100);
	
	map_skill("force","hanmei-force");
	map_skill("unarmed","zhaixin-claw");
	map_skill("move", "anxiang-steps");
	map_skill("parry", "qingfeng-sword");
	map_skill("sword", "qingfeng-sword");
    	map_skill("dodge", "anxiang-steps");

	setup();
    	carry_object(__DIR__"obj/gcloth")->wear();
    	carry_object("/obj/weapon/sword_thin")->wield();

}
