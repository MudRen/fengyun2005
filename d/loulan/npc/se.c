#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("江左司徒", ({ "jiangzuo situ","situ" }) );
        set("gender", "女性" );
        set("long",
"一个青衣妇人，看上去面慈目善，但隐约泛出一丝诡异，也露出一股慑人
的妖氛；乃快活王手下四使之色使，专为其各处征选绝代佳人。\n" 
                );
        create_family("快活林", 1, "色使");
        set("attitude", "peaceful");
        set("class", "bat");
        set("reward_npc", 1);
		set("difficulty", 2);
	
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
        
		set("age", 45);
        
        set("combat_exp", 1000000);
        
		set_temp("apply/armor",50);
	    
	    
	    set("inquiry", ([
	    	"阴阳和合散":"据说是当年一阵风"YEL"韩风"CYN"常用的迷药，有了它，烈女也会变成荡娃。\n",
	    	"韩风":		"这个我就不太清楚了，听说他已经洗手不干了，估计是老得不行了吧。\n",
	    ]));
	        
        set("chat_chance", 1);
        set("chat_msg", ({
                "江左司徒甩了甩手中青手帕，似笑非笑般看着你。\n",
                "江左司徒低声道：若是能搞到"YEL"阴阳和合散"NOR"，王爷一定重重有赏。\n",
                }) );

        set_skill("unarmed", 150);
        set_skill("blade", 150);
        set_skill("bat-blade", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("move", 300);
        set_skill("meng-steps", 120);
        set_skill("nine-moon-claw", 120);
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup();
		carry_object("/obj/weapon/blade")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
}


void init()
{
        object  ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);
}

int greeting(object ob)
{	
	object room;
	if (!ob || environment(ob)!= environment(this_object()))	return 1;
	if ( userp(ob) && ob->query("gender") == "女性" )
	{
            if( ((int)ob->query_per() >= 20) && ((int)ob->query("age") <= 30)
            	&& ob->query("class")!="knight" )
		{
			if(!objectp(room = find_object("/d/loulan/zhenchunyuan")))
				room = load_object("/d/loulan/zhenchunyuan");
			message_vision("$N上一眼，下一眼仔细看着$n，嘴角露出了满意的笑容。\n",this_object(),ob);
			message_vision("$N柔声道：小美人儿，王爷要是看中你，真是你几辈子也修不来的福气啊......\n",this_object());
			message_vision("$N纤指一挥，一股浓香向$n扑鼻而来。\n",this_object(),ob);
			ob->unconcious();
			ob->move(room);
 		}
		return 1; 
	}
	else
		return 0;
}


int accept_object(object who, object ob)
{	
	mapping all;
	
	if (REWARD_D->check_m_success(who,"酒色财气"))	return 0;
		
	if (ob->query("name")==HIY "阴阳和合散"NOR )
	{
		message_vision("$N柔声道：王爷这下可不用愁了，任她三贞九烈，也要乖乖听命我家王爷。\n",this_object(),this_player());
		REWARD_D->riddle_set(who,"酒色财气/se", 1);
		tell_object(who, WHT"你完成了『酒色财气』中的“色”\n"NOR);
		all = who->query("riddle/酒色财气");
		if (mapp(all) && sizeof(all) == 4)
			REWARD_D->riddle_done(who,"酒色财气",50,1);	
		return 1;
	}
	else
	{
        message_vision("$N摇头说道：这个是什么东西？我可无福消受。\n",this_object()); 
		return 0;
	}
}
