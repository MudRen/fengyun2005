inherit NPC;
#include <ansi.h>

void create()
{
	set_name("长发少女", ({ "beauty" }) );
	set("gender", "女性" );
	set("title", GRN "轻纱朦胧"NOR);
	set("age", 18);
	set("long",
        	"一个身穿轻纱的长发少女，赤着雪白的双足，手托香腮，曼声低唱。。\n");
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 2);
        set("chat_msg", ({
		"长发少女正随着歌声，婀娜起舞，轻纱飘扬，春光微泄。。\n",
        }) );
	set_skill("unarmed",20);
	set_skill("dodge",100);
	setup();
	carry_object(__DIR__"obj/qinsha")->wear();
}