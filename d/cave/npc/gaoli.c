#include <ansi.h>
inherit NPC;

void create()
{
    set_name("高立", ({"gao li","gao"}) );
    set("gender", "男性" );
    set("nickname", HIC"夺命枪"NOR);
    set("title", "青龙会 刺客");
    set("long", "
高立的脸仿佛永远都隐藏在阴影里。他身上穿着件宽大的蓝布道袍，非常宽大，
因为他必须在道袍下藏着他那对沉重而又锋利的银枪。\n");
 	set("attitude", "friendly");
    	set("age", 25);
    	   	
    	set("combat_exp", 4000000);
    	set("class","officer");
	
		set("reward_npc", 1);
        set("difficulty", 5);
	
		set_skill("spear", 200);
		set_skill("parry", 150);
		set_skill("yue-spear", 160);
		set_skill("dodge", 150);
		set_skill("move", 150);
		set_skill("dragonstrike",150);
		set_skill("unarmed",150);
		set_skill("puti-steps",200);
		set_skill("force",100);
		set_skill("manjianghong",120);
	
	map_skill("force","manjianghong");
	map_skill("unarmed","dragonstrike");
	map_skill("parry","yue-spear");
	map_skill("spear", "yue-spear");
	map_skill("dodge","puti-steps");
	map_skill("move","puti-steps");
	
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: command("perform zonghengtianxia") :),    
        }) );	
        
	set("chat_chance", 1);
    	set("chat_msg", ({
        HIR "高立从鲜血之中想努力爬向双双，嘶声道：双。。双。。现在我的眼\n也瞎了，在我心中，你。。你永远是最美丽的。。\n"NOR,
        HIR"高立吐了口血，颤巍巍从怀中掏出一束滴血的玫瑰和小布娃娃，\n一点一点努力地爬向双双。\n"NOR,
    	}) );

    	setup();
    	carry_object(__DIR__"obj/taocloth")->wear();
    	carry_object(__DIR__"obj/bravespear")->wield();
    	carry_object(__DIR__"obj/bloodrose");
    	carry_object(__DIR__"obj/doll");
}

int accept_object(object who, object ob){
	object xi, box;
	
	if (this_object()->is_fighting())	return 0;
		
	if(ob->query("id") == "jadebox" && ob->name() == "雀翎玉盒"){
		message_vision("$N轻轻扶起血泊中的$n，把雀翎玉盒轻轻放在$n怀中，对着他轻轻耳语一番。。\n", 
				who, this_object()); 
		who->start_busy(3);
		if(!present("ximen yu", environment())){
			return 0;
		}
		if(present("ximen yu", environment()) && present("shuang shuang", environment())){
			xi = present("ximen yu", environment());
			call_out("kill_xi", 2, who, xi);
		} else if (present("ximen yu", environment()) && !present("shuang shuang", environment())){
			message_vision("$N长叹一声：晚了，太晚了。。\n", this_object());
			message_vision("$N手中长枪倒转刺向自己心口。。。。\n", this_object());
			box = new(__DIR__"obj/jadebox");
			if(objectp(box)){
				box->move();
			}
			call_out("dead", 1);
			return 1;
		}
		return 1;
	}
	return 0;
}

int kill_xi(object me, object xi){
	if(!interactive(me) || environment(me) != environment()){
		return 0;
	}
	message_vision(RED"\n$N紧紧地握了握拳头，擦了擦嘴角的鲜血，突然怒喝一声，笔直而立，握枪在手。\n"NOR,
			this_object()); 
	message_vision("$N默默望了眼昏迷中的双双，对西门玉沉声喝道：西门，看枪！\n",
			this_object()); 
	message_vision(HIW"\n$N手中银枪仿佛疾电般脱手。。。。\n", this_object()); 
	message_vision(HIW"        银枪有如蛟龙出海。 “噗”的一声，竟已贯穿了西门玉的咽喉。\n\n"NOR,
			this_object()); 
	xi->killed(me);	
}


void dead(){
	this_object()->die();
}

void do_leave(object me){
	call_out("leave", 1, me);
}

void leave(object me){
	object shuang;
	
	if(!interactive(me) || environment(me) != environment()){
		if(present("shuang shuang", environment())){
			shuang = present("shuang shuang", environment());
			message_vision("$N挣扎着抱起双双，消失在黑暗之中。。。 \n", this_object());
			destruct(shuang);
			destruct(this_object());
		}
		return;
	}
	if(present("shuang shuang", environment())){
		shuang = present("shuang shuang", environment());	
		message_vision("$N对着$n点了点头，然后挣扎着抱起双双，消失在黑暗之中。。。\n",
				this_object(), me); 
		REWARD_D->riddle_done( me, "智救高立", 10, 1);
		destruct(shuang);
		destruct(this_object());
	}
	return;
}