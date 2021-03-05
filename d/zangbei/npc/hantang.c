#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int estate();

void create()
{
    	set_name("韩棠",({"han tang","han"}));
//	set("title","与世无争");
   	set("long","
韩棠并不野蛮，并不凶恶．只不过眉目间仿佛总是带着一种说不出的冷漠之
意，无论谁都没法子和他亲近。他自然也不愿和任何人亲近，随便在什么地
方．他都是站得远远的。若有人走近他七尺之内，他立刻就会走得更远些。
除了在老伯的面前，也从来没有人见他开过口。\n");
     	
     	set("gender","男性");
     	set("group","juyuan");
     	
    	set("age",32); 	 	
    	
    	set("combat_exp",8500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"老伯":	"无论老伯做什么，都是对的，无论老伯对我怎么样，我都不会埋怨。",
		"孙玉伯":"无论老伯做什么，都是对的，无论老伯对我怎么样，我都不会埋怨。",
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"\n韩棠坐在鱼池旁，钓竿已扬起鱼已被钧钩住，他就静静地坐在那里
欣赏鱼在钓钩上挣扎。\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_u","demon-strike",2);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "灰鼠袍",
    						"long": "一件用灰鼠皮织成的长袍。\n",
    						"value": 10, 
    						 ]))->wear();    
 
}

void init()
{       
        object ob;

        ::init();
        if (environment(this_object())->query("home"))
        if( interactive(ob = this_player()) && !query("in_show") && !is_fighting() ) {
				if (REWARD_D->riddle_check(ob,"菊园传奇")==5	)
//                if (ob->query("marks/kuaihuo/菊园刺客")==2 
//                	&& !ob->query("marks/kuaihuo/韩棠"))
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
	object /*me,*/ peng1, peng2, peng3, peng4;
        if( !ob || environment(ob) != environment() ) return;
	set("in_show",1);
	delete("chat_chance");
	message_vision(CYN"
忽然，四个锦衣华服的彪形大汉箭一般窜过来，团团围住了韩棠。

领头一人道：“屠城屠大鹏。”

另外三人也立刻报出了自己的名姓，

“罗江罗金鹏。”

“萧安萧银鹏。”

“原冲原怒鹏。”

原来是万鹏王手下十二飞鹏帮的四大帮主，这世上还没有任何人能单独对付他们四个。\n"NOR,ob);
	peng1 = new(__DIR__"peng1");
	peng1->move(environment());
	peng2 = new(__DIR__"peng2");
	peng2->move(environment());
	peng3 = new(__DIR__"peng3");
	peng3->move(environment());
	peng4 = new(__DIR__"peng4");
	peng4->move(environment());
	peng1->do_ask(ob);
	return;
}



void die(){
	object *inv;
	int i, check, num;
	
	inv = all_inventory(environment(this_object()));
	num = sizeof(inv);
	for (i=0;i<num;i++){
		if (inv[i]->query("group")=="khlr") {
			destruct(inv[i]);
			check = 1;
		}
	}
	if (check)
		message_vision("\n只听唿哨一声，锦衣大汉们消失在黑暗里。\n",this_object());
	::die();
}
		