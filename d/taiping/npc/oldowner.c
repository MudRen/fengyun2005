#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int birdcase();

void create()
{
    	set_name("老掌柜",({"old owner","owner"}));
    	set("long","平安客栈的老掌柜，他呆呆地看着窗外的鸟笼，眼睛里的表情忽然也变得很奇怪。\n");
    	set("gender","男性");
    	set("age",62);
    
		set("combat_exp", 1500000);
		set("attitude","friendly");
	
	
		set("death_msg",CYN"\n$N缓缓道：不悔，不悔。。 \n"NOR);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
        	}) );
    	set("inquiry", ([
        	"荒唐" : 	"鹦鹉楼里的那一个晚上，我一辈子都忘不了啊！\n",
        	"鸟笼" :  (: birdcase() :),
   		]));
    	set("chat_chance",1);
    	set("chat_msg",({
		"老掌柜看着窗外的鸟笼，眼睛里的表情忽然也变得很奇怪。\n",
		"老掌柜道：“鬼门关开了，冤魂野鬼都出来了，到了人间……”\n",		
		"老掌柜目光遥视着窗外，过了很久，才缓缓道：“我这一辈子，都是在规规
矩矩的做人，可是我也曾荒唐过一次。”\n",		
    	}) );
	
	auto_npc_setup("wang",150,110,0,"/obj/weapon/","fighter_w","taiji",1);
	
	set_skill("iron-cloth",150);
	setup();
	carry_object(__DIR__"obj/yandou");
	carry_object("obj/armor/cloth")->wear();
}


int birdcase() {
	object ob,me;
	ob=this_object();
	me=this_player();

	message_vision(CYN"	
老掌柜看着窗外的鸟笼，眼睛里的表情忽然也变得很奇怪，过了很久，才
叹了口气，道：“那本来是只鹦鹉，又活泼，又可爱，只要看见过它的人，
都想不到它忽然会死。”

老掌柜道：“那天晚上，我本来已睡了，忽然听见它在叫，就好像……就
好像一个人在害怕时发出的那种惊呼一样。”他的脸也已因恐惧而扭曲，
“等到我赶出来时，它已经死了，死得好惨。”\n\n"NOR,ob);
	me->set("marks/parrot/老掌柜",1);
	return 1;
}


	
	