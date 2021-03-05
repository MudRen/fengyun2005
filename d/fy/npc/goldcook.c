// fatman.c
#include <ansi.h>

inherit NPC;
int tell_him();

void create()
{
        set_name("大厨", ({ "big cook","cook" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一个手艺精湛的大厨。\n");
	set("attitude", "heroism");
        set("combat_exp", 20000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "大厨在厨房里忙前忙后，满头大汗。\n",
        }) );

    	set("inquiry", ([
	        "帮忙" : (: tell_him :),
	        "工作" : (: tell_him:),
	        "work" : (: tell_him :),
	        "help" : (: tell_him:),
	        "老鼠":	 "唉，这老鼠到处乱跑，你仔细看看说不定能发现它们的老巢！\n",
        	"rat":	 "唉，这老鼠到处乱跑，你仔细看看说不定能发现它们的老巢！\n",
        	"mouse":	 "唉，这老鼠到处乱跑，你仔细看看说不定能发现它们的老巢！\n",
        ]));
        
        set_skill("unarmed", 130);
        set_skill("parry", 30);
	set_skill("dodge", 30);
	
	setup();
    
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/luwei");
        
}


int tell_him(){
	object ob, me = this_player();
	ob = this_object();
	
	if (!QUESTS_D->verify_quest(me,"金狮大厨")) {
		command("say 帮忙？你会烧菜么，瞧你这样，还是去仓房运货吧。");
		return 1;
	}
	if (me->query_temp("marks/js_cook_mice")) {
		tell_object(me, "大厨说：我叫你去办的事儿做完了么？\n");
		return 1;
	}
	
	if (me->query_temp("marks/ask_js_cook")<3) {
		me->add_temp("marks/ask_js_cook",1);
		if (random(2))
			message_vision("大厨在灶边忙得团团转，似乎没听到$N的话声。\n",me);
		else
			message_vision("大厨抬起头来看了$N一眼，又低下头去忙活了。\n",me);
		return 1;
	}
	
		
	tell_object(me, "大厨拿起菜刀在围裙上擦了擦说：想帮忙啊？中！这些天"YEL"老鼠"NOR"闹腾得厉害，你看看有什么法子？\n");
	me->delete_temp("marks/ask_js_cook");
	me ->set_temp("marks/js_cook_mice",1);
	return 1;
}
		