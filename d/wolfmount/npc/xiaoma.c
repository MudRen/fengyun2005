#include <ansi.h>
inherit NPC;

void create()
{
	set_name("小马", ({"xiao ma","ma"}) );
	set("title" , "愤怒的");
	set("gender", "男性" );
	set("age", 22);
	set("per", 30);
	set("no_arrest",1);
	set("no_heal",1);
	set("free_hit",1);
	
	set("str",60);
	set("long","
一个倔强、骄傲，全身都充满了叛逆性的小伙，别人都管他叫愤怒的小马。
他浑身都是伤口，你似乎可以帮他包扎（ｃｕｒｅ）一下。\n"
	);
		
	set("combat_exp", 5000000);
	set("score", 30000);
	set("chat_chance",1);
	set("chat_msg",({
		"小马握紧了拳头，愤怒的火焰在眼中燃烧。\n",
		"“小琳，小琳！”小马在溪水中挣扎前爬，浑身鲜血染红了清澈如镜的溪水。\n",
	}) );
	
	    set("inquiry", ([
        
        	"小琳" : "小琳、小琳、被太阳使者抓去了！！！",
        	"老皮" : "老皮是我的"WHT"朋友"NOR"，被太阳使者抓去了！",
        	"太阳使者" : "小琳和老皮都被太阳使者抓去了！！！",	
        	"朋友":		"如果你孤身犯险，告诉（whisper）老皮你是我的朋友，他也许会帮你。\n",	
        
        ]) );
	
	set_skill("move", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("unarmed",200);
	set_skill("tigerstrike",300);
	set_skill("xueyeqianzong",200);
	
	map_skill("unarmed","tigerstrike");
	map_skill("dodge","xueyeqianzong");
	map_skill("move","xueyeqianzong");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		add_action("do_cure", "cure");
		add_action("do_answer","answer");
		add_action("do_accept","accept");
	}
}

int do_cure(string arg)
{
	object me;
	me = this_player();
	if( arg != "xiao ma" )
		return notify_fail("你要为谁治疗？\n");
	else if( this_object()->query("xiaoma_cured") )
		return notify_fail("小马说：不用麻烦了，我的伤势已经差不多好了！\n");
	else
	{
		if (me->query("timer/cure_xiaoma") + 10800 > time())
		{
			message_vision(CYN"小马说：你怎么这么快就回来了，再等等再试吧。（解此谜题间隔为三小时）\n"NOR, me);
			return 1;
		}
		
		if ( me->query("force") < 1000)
		{
			return notify_fail("你的内力不够深厚，真气不够用来治疗！\n");
		}
		else
		{
			write(HIW "你全身放松，坐下来为小马运功疗伤。\n"NOR);
			message_vision(HIW"小马因痛苦而扭曲的面孔慢慢平静了下来，喘着气一时说不出话来。\n"NOR , me);
			me->add("force",-1000);
			this_object()->set("xiaoma_cured",1);
			me->start_busy(5);
			call_out("ask_help", 5, me);
			return 1;
		}
	}
	return 1;
}

void ask_help(object me)
{
	object obj;
//	if ( me->query("宿命B/黄山_云海")> 0 && me->query("宿命B/黄山_云海")%2 == 0)
	if (REWARD_D->check_m_success( me, "狼山锄奸"))
	{
		message_vision(CYN"小马喘了口气说：谢谢你杀死了太阳使者。\n"NOR, me);
		return;
	}
	
	if (me->query("timer/cure_xiaoma") + 10800 > time())
	{
		message_vision(CYN"小马说：你怎么这么快就回来了，再等等再试吧。（解此谜题间隔为三小时）\n"NOR, me);
		return;
	}
	
	me->set("timer/cure_xiaoma", time());
	if (random(2))
	{
		message_vision(HIY"小马无神的眼睛突然亮了起来，用一种奇怪的眼神看着$N。\n"NOR, me);
		message_vision(HIY"小马抱拳说道：这位"+RANK_D->query_respect(me)+"，不知是否能助我救出小琳？（Answer Yes／No）\n"NOR, me);
		me->set_temp("marks/wolf_xiaoma_asking",1);
	}
	else
	{
		message_vision(HIY"一会儿，小马无神的眼睛突然亮了起来，感激的看着$N。\n"NOR, me);
		message_vision(HIY"小马向$N一抱拳，道：“我的伤势并无大碍，不知可否再麻烦这位英雄，\n帮我救出老皮和小琳？”。（Accept Yes／No）\n"NOR, me);
		me->set_temp("marks/wolf_xiaoma_questing",1);
		return;
	}
}

void reset(){
	set("xiaoma_cured",0);			// Not really fool-proof, but might be ok :D
}



int return_home(){				
	object room;
	object wen;
	if (is_busy() || is_fighting() 
		|| query_temp("scene_start")) {
			call_out("return_home",60);
	} else {
		room = find_object("/d/wolfmount/brook3");
		if (!room) room = load_object("/d/wolfmount/brook3");
		wen = present("sun legate");
		if (wen) {
			wen->set("chat_chance_combat", 40);
			wen->set("force_factor",120);
			wen->set("combat_exp", 10000000);
		}	
		set("xiaoma_cured",0);
		set("free_hit",1);
		set("chat_chance",1);
		ccommand("sigh");
		message_vision("$N慢慢转身离开了。\n",this_object());
		move(room);
	}
	
	return 1;
}

// This is called by sun legate when he dies... 5 mins nothing happesn --> xiao ma left			

int delete_mark(){
	delete_temp("scene_start");
}

int delete_scene(){
	call_out("delete_mark",120);
	return 1;
}	

int do_answer(string arg)
{
	object me, obj;
	object room;

	obj = this_object();
	me =this_player();
	if(!me->query_temp("marks/wolf_xiaoma_asking")) return 0;

	if( arg == "yes" || arg == "YES" )
	{
		me->delete_temp("marks/wolf_xiaoma_asking");
		message_vision("$N握紧拳头道：小琳被太阳使者的药物控制，我们就到太阳湖的花舟找\n太阳使者决一死战！花舟再见！\n", obj);
		me->set_temp("marks/wolf_xiaoma_good", 1);
		REWARD_D->riddle_set( me, "狼山锄奸",1);
//		me->set("marks/wolf_xiaoma_good", 1);
		message_vision("$N转身向远处的湖泊走去......\n", obj);
		obj->set("chat_chance",0);
		room = find_object("/d/wolfmount/flowerboat");
		if(!objectp(room)) room = load_object("/d/wolfmount/flowerboat");
		obj->move(room);
		call_out("return_home",300);
		return 1;
	}
	else if ( arg == "no" || arg == "NO" )
	{
		message_vision("$N神色黯然：看来"+me->name()+"也帮不了我！\n", obj);
		me->delete_temp("marks/wolf_xiaoma_asking");
		return 1;
	}
	else
	{
		tell_object(me, name()+"道：我不大明白你的意思哎！\n");
		return 1;
	}
}

int do_accept(string arg)
{
	object me, obj;
	obj = this_object();
	me =this_player();
	if(!me->query_temp("marks/wolf_xiaoma_questing")) return 0;

	if( arg == "yes" || arg == "YES" )
	{
		message_vision("$N朗声笑道：多谢这位英雄！\n", obj);
		me->delete_temp("marks/wolf_xiaoma_questing");
		message_vision("
$N神色凝重道：小琳被太阳使者的药物所控制，只有杀了太阳使者才会解除控制！
老皮是我的朋友，被太阳使者抓去了，如果你遇到他，悄悄告诉他我的名字，再告诉
他你是我的朋友，他就会帮你！\n", obj);
		me->set_temp("marks/wolf_xiaoma_normal", 1);
		REWARD_D->riddle_set( me, "狼山锄奸",1);
//		me->set("marks/wolf_xiaoma_normal", 1);
		obj->set("chat_chance",0);
		return 1;
	}
	else if ( arg == "no" || arg == "NO" )
	{
		message_vision("$N长叹一声：求人不如求自己．大不了拼得一死！\n", obj);
		message_vision("$N转身离去，孤单的身影渐渐走远......\n", obj);
		me->delete_temp("marks/wolf_xiaoma_questing");
		destruct(obj);
		message_vision("$N失魂落魄，羞愧难当，为自己的懦夫行为感到万分后悔．\n",me);
		return 1;
	}
	else
	{
		tell_object(me, name()+"道：我不大明白你的意思哎！\n");
		return 1;
	}
}

void die()
{
	object wen, xiaolin;
	
	wen = present("sun legate");
	if (wen) {
		message_vision(HIR"$N狂笑几声，小马死了，你也别想活着出去！\n"NOR, wen);
		wen->set("chat_chance_combat", 40);
		wen->set("force_factor",120);
		wen->set("combat_exp", 10000000);
	}	
	
	if (xiaolin = present("xiao lin",environment(this_object())))
	{
		xiaolin->set("xiaoma_died",1);
	//	this_player()->set("marks/wolf_xiaoma_normal", 1);
	//	this_player()->delete("marks/wolf_xiaoma_good", 1);
	}
	::die();
}
