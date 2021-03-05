#include <ansi.h>
inherit NPC;
void create()
{       
        set_name("蓝兰", ({ "lan lan","lan" }) );
        set("long", "她犹如鲜花般盛开在你的面前，千娇百媚。\n");
        set("age", 20);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("combat_exp", 1500000); 
        set("inquiry", ([
        	"小马": "他前去帮助朱五太爷找出幕后主使，但是现在他不见了。\n",
	]) );
        set("chat_chance",1);     
        set("chat_msg",({
		"蓝兰恨恨道：“那头驴子，又不知道死到哪去了。”\n",
	}) );

        setup();
        carry_object(__DIR__"obj/blue_skirt")->wear();
}
