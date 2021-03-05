// wenshi.c 

#include <ansi.h>

inherit NPC;

void create()
{
    	set_name("中年文士", ({ "wenshi" }) );
	set("gender", "男性");
	set("age", 42);
	set("long",
		"这位中年文士正在潜心钻研着什么，丝毫没注意有人进来。\n");
    	set("combat_exp", 650000);
	set("attitude", "friendly");

    	set("chat_chance", 2);
    	set("chat_msg", ({
        	"中年文士踱了两步道：奇门五行之术，奥妙多端，... \n",
        	"中年文士面露得意之色道：世人但知晓奇门五行，却不知反其道而行，
更是鬼神莫测！\n",
    	}));
    	set("inquiry", ([
            	"奇门五行" : "似乎是左右后前右左后。\n",
		"maze" : "似乎是左右后前右左后。\n",
     	]));
     	setup();
     	carry_object("/obj/armor/cloth")->wear();
}

