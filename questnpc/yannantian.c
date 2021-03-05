#include <ansi.h>
#include <combat.h>
//inherit QUESTNPC;
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
void do_fight();
object offensive_target(object me);
void create()
{
	set_name("燕南天", ({ "yan nantian", "yan" }) );
	set("gender", "男性" );
	set("title","冀人   天下第一剑");
        set("nickname",CYN"冠盖满京华 斯人独憔悴"NOR);
        set("quality","good");
        set("age", 48);
	set("int", 65);
	set("per", 22);
	set("str", 50);
	set("dur", 42);
	set("cor", 60);
	set("agi",80);
    set("long",
"这人身高八尺开外，眯着眼睛，就像是条懒睡的猛虎。阳光外面斜斜地照过来，照着他两
条黑墨般的浓眉，照着他棱棱的颧骨，也照着他满脸青惨惨的胡渣子直发光。
\n"
		);
        set("force_factor", 200);
        set("max_force",9000);
	set("force",9000);
        set("force_factor",100);
        set("combat_exp", 90000000);
        set("score", 53000);
        set_skill("unarmed", 220);
        set_skill("sword", 310);
        set_skill("force", 310);
        set_skill("parry", 250);
        set_skill("literate", 110);
	set_skill("dodge", 290);
	set_skill("jiayiforce",150);
	set_skill("sky-sword",300);
	set_skill("sky-steps",300);
	
		
		map_skill("force", "jiayiforce");
		map_skill("sword","sky-sword");
		map_skill("dodge","sky-steps");
		map_skill("move","sky-steps");
		map_skill("parry","sky-sword");
		set("chat_chance",3);
		set("chat_msg",({
			"燕南天微睁虎目，望着天边那一抹似血斜阳，沉声道：“即便寻到天涯海角，
燕某人也要把小鱼儿找到，一定要找到。”\n",
		})	);
		set("chat_chance_combat",50);
		set("chat_msg_combat",({
			(:perform_action,"sword.tianrenheyi":),
		})	);
      
	setup();
	//carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

void init()
{
	::init();
	add_action("do_cry","cry");
}

void heart_beat()
{
	object me,enemy;
	
	::heart_beat();
	
	if(is_fighting())
	{
	if(!query("betrayed_target"))
	{
		enemy=offensive_target(this_object());
		if(enemy=query("fake_yu"))
		{
			message_vision(HIR"燕南天无可置信的看着$N，身体竟不住颤抖，声音中充满着悲怆和愤怒：
“好。。。好。。。好。。。竟然冒充小鱼儿欺骗于我，我不诛此獠，势不为人！！”\n"NOR,enemy);
			set("betrayed_target",enemy);
			set("perform_allowed",1);
		}
	}
	if(query("perform_allowed")&&(!query_busy())&&random(3))
		command("perform tianrenheyi");
	}
	
	if(query("cried")==5)
	{
		me=query("fake_yu");
		if(environment(me)!=environment()) return;
		message_vision(HIC"燕南天目不转睛盯着$N看了半天，拉着$N的手，喃喃道：很好，很好，很好，
…果然是我义弟江枫的儿子。
燕南天虎目中尽是泪水，目光眺向远方，似乎想起了当年不堪回首的往事。\n"NOR,me);
		delete("cried");
		start_busy(10);
	}
		
}

int do_cry(string arg)
{
	object ob,me,*applyname;
	
	if(!arg) return 0;	
	ob=find_living(arg);
//	if(ob!=this_object()) return 0;
	me=this_player();
	applyname=me->query_temp("apply/name");
//	if(!applyname) return 0;
//	if((string)applyname[0]!="芳儿") return 0;
	ob->add("cried",1);
	if(!query("fake_yu"))
		set("fake_yu",me);
	return 0;
}
	
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}
