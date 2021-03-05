#include <ansi.h>
inherit SMART_NPC;

int answer();

void create()
{
        set_name("石驼", ({ "shi tuo","shituo" }) );
        set("title","又聋又哑");
        set("gender", "男性" );
        set("age", 42);
	set("long","
黑凛凛的大汉。反穿着老羊皮背心，露出一身比铁还黑、还结实的肌肤。
他一张脸竟像是风干了的桔子皮，凸凸凹凹，没有半寸光滑干净的地方。
再看他一双眼睛，灰蒙蒙的，简直连眼白和眼珠子都分不开来，谁也想
不到世上会有人生着这样的眼睛。他眼睛虽在瞪着你，却又好像并没有
瞧见你似的，眼睛里显似充满邪气，却又似空洞得什么都没有。\n");
		set("combat_exp", 6400000);
		set("class","beggar");
		set("reward_npc",1);
		set("difficulty",3);
        
		set("inquiry",([
			"沙漠": (: answer() :),
			"desert": (: answer() :),		
		]));
	
		set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(70) :),
	        }) );
        	
		set("attitude", "friendly");
      	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();
        carry_object(__DIR__"obj/scloth")->wear();

}


int answer(){
	message_vision("石驼不言不语，翻开手掌，伸出三个手指在你面前晃了晃。\n",this_object());
	return 1;
}


