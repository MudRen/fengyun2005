#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("孙玉伯",({"sun yubo","sun"}));
	set("title",HIY"菊花园"NOR);
	set("long","
老伯就是孙玉伯，没有人真正知道孙玉伯究竟是个怎么样的人？究竟能做什么
事。但无论谁有了困难有了不能解决的困难时，都会去求他帮助。他从不托词
推诿，也绝不空口许诺，只要他答应了你，天大的事你都可以放在一边，因为
他绝不令你失望。你不必给他任何报酬甚至于不必是他的老朋友。无论你多么
孤苦穷困，他都会将你的问题放在心上，想办法为你解决。因为他喜欢成全别
人，喜欢公正，他憎恶一切不公正的事，就像是祈望丰收的农人，憎恶蝗虫急
于除害一样。他虽然不希望报酬，但报酬却还是在不知不觉给了他。\n");
   	
     	set("gender","男性");
     	
    	set("age",72); 	 	
    	
    	set("combat_exp",100000000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"*":	(: message_vision(CYN"老伯笑笑，一言不发。\n"NOR,this_object()) :),
   		]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","taiji",1);
	
		setup();
    	carry_object(__DIR__"obj/cyancloth")->wear();
 
}


string *event1_msg=	({
	
	"忽然自高楼失足，忽然自光明跌人黑暗的无底深渊，
就连这些都没有老伯现在所体验的感觉更可怕。",

    	"因为他已看到站在他床前的赫然竟是律香川。",

    	"正是他最信任的人．他的朋友，他的儿子。",

    	"律香川脸上一点表情都没有，冷冷地看着他，忽然道：我用的是七星针。",

    	"老伯咬紧牙，已可感觉到自己的指尖冰冷。",

    	"律香川道：你常说我的七星针已可算是天下暗器第一，连唐家的毒砂和毒
蒺藜都比不上，因为那两种暗器还有救，七星针却没有解药。",

    	"律香川道：不过，若不是这小子引开你的注意力，我也不能得手。",
    	
    	"老伯的呼吸已渐渐短促，道：我有什么地方亏待了你？",

    	"律香川道：没有。",

    	"老伯道：那么你为何如此恨我？",

    	"律香川道：我不恨你，我只不过要你死，我只是要你的地位和财宝。",
    	
    	"律香川转过头来对你说：现在你已经可以动手了。",

});

void init(){
		add_action("do_answer","answer");		
		if (interactive(this_player()))
			this_player()->delete_temp("marks/kuaihuo/laobo_1");
		::init();
}


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) || me->is_fighting()) {
		return;
	}
	
	tell_object(me,CYN"\n"+event1_msg[count]+"\n"NOR);
	if(++count==sizeof(event1_msg))
	{
		tell_object(me,WHT"\n现在是完成高老大使命的最好时机，你是否立刻动手？\n"NOR);
		tell_object(me,WHT"answer yes/no\n"NOR);
		me->set_temp("marks/kuaihuo/laobo_1",1);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}

int accept_object(object me, object item) {
	object ob, lu;
	if (item->name()!="风鸡")	return 0;
	ob = this_object();
	if (item->query("item_owner")!= me)
		return notify_fail("老伯说：我怎么可以随便要你的东西呢？\n");
	
	message_vision(CYN"
老伯慢慢地站起身慢慢地走到你面前，笑了笑，赞赏地拍了拍你的肩头。\n"NOR,ob);
	item->move(ob);
	ob->ccommand("eat chicken");
	me->delete_temp("marks/kuaihuo/lv_cook");
	message_vision(CYN"
老伯忽然一愣，左手一颤，风鸡掉在地上，右手一伸，已点了你的穴道。

就在这时，门忽然披撞开，撞得粉碎。

一条人影掠进来。

七点寒星，闪电般射入了老伯的背脊！\n\n"NOR,ob);
	
	me->start_busy(1000);
	ob->set("combat_exp",5000000);
	ob->set("level", 90);
	ob->set("eff_kee",5000);
	ob->set("kee",5000);
	ob->set("str",80);
	ob->set("no_heal",1);
	lu = new(__DIR__"lv2");
	lu ->move(environment(me));
	ob->set("NO_KILL","你现在不能动弹，还杀什么人？\n");
	lu->set("NO_KILL","你现在不能动弹，还杀什么人？\n");
	call_out("event1",2,me,0);
	return 1;
}

int do_answer(string arg){
	object me, ob, lu;
	me = this_player();
	ob = this_object();
	
	if (!me->query_temp("marks/kuaihuo/laobo_1"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no ");
	
	if (arg == "yes") {
		message_vision(YEL"
律香川一伸手拍开你被封住的穴道，你大喝一声向老伯展开进攻。\n"NOR,me);
		ob->delete("NO_KILL");
		lu = present("lv xiangchuan",environment(me));
		lu->delete("NO_KILL");
		me->stop_busy();
		ob->kill_ob(me);
		me->kill_ob(ob);
		me->delete_temp("marks/kuaihuo/laobo_1");
		me->set_temp("marks/kuaihuo/想杀老伯",1);	
		return 1;
	}
	if (arg = "no") {
		message_vision(YEL"
$N摇摇头说：我不能乘人之危，何况，这些天我已了解老伯的为人，我再不能
助纣为孽，真正该死的是你们这批见利忘义之徒。\n"NOR,me);
		tell_object(me,YEL"
你强运真气，冲开被点的穴道。\n"NOR,me);
		me->stop_busy();
		ob->delete("NO_KILL");
		lu = present("lv xiangchuan",environment(me));
		if (lu) {
			lu->delete("NO_KILL");
			lu->kill_ob(me);
		} else {
			tell_object(me,"bugs, please report it to wizard.\n");
			return 1;
		}
		me->kill_ob(lu);
		me->delete_temp("marks/kuaihuo/laobo_1");
		me->set_temp("marks/kuaihuo/想杀律香川",1);
		return 1;
	}
	return 1;
}


void die(){
	object room, sunju, bed, me, owner,lu;
	
	if(objectp(me=query_temp("last_damage_from") ))     
        	if(owner=me->query("possessed")) {
			me = owner;
	} 
	if (!me) ::die();
	
	room = find_object(AREA_ZANGBEI"tunnel4");
	if (!room) room = load_object(AREA_ZANGBEI"tunnel4");
	if (!sunju = present("sun ju", room)) {
		
		if ( me->query_temp("marks/kuaihuo/想杀老伯"))
			REWARD_D->riddle_set(me,"菊园传奇",13);
	//	me->set("marks/kuaihuo/杀孙玉伯",1);
		lu = present("lv xiangchuan",environment(me));
		if (lu) {
			message_vision(CYN"
律香川轻轻拍了拍手笑道：“大功告成，你选择的很正确。”

律香川又道：“高老大要的地契，一会儿到我屋中来取。”

话音未断，已越窗而去。\n\n"NOR,me);
			destruct(lu);
		}
		::die();
		return;
	}
	
	message_vision(CYN"
老伯忽然笑了笑，道：你好像也忘了我说的一句话，我说过天下没有绝对的事，
你却一定要说我绝对没法逃走。

老伯的人忽然从床上落了下去，忽然不见了。

“夺，夺，夺”一连串急响，十数点寒光打在床上。

但床上却已没有人。

律香川长叹一声：完了，我们败了！！！

说罢脸色惨白，越窗而出。\n\n"NOR,this_object());
	lu = present("lv xiangchuan",environment(this_object()));
	if (lu) {
		destruct(lu);
	}
	environment(this_object())->set("escaped",1);
	tell_object(me,WHT"解谜失败。。。。从头再来吧。\n"NOR);
	REWARD_D->riddle_clear(me,"菊园传奇");
	me->delete_temp("marks/kuaihuo");		
	me->set("timer/菊园失败",time());		// Time to restart.
	destruct(this_object());
	return;
}


void thank_you(object me){
	
	message_vision(CYN"

老伯笑了，但笑容中却仿佛还是说不出的凄凉和辛酸。

律香川就像是他亲手栽成的树木砍断了！

老伯的笑容虽带些伤感，但已渐渐明朗，一字字道：

“你千万莫要再为任何事烦恼，快放下心事，去叫小蝶，快去…”

“我要你们为我活下去，好好地活下去，快快乐乐地活下去！”\n\n"NOR,me);
	this_object()->delete("no_heal");
	this_object()->set("combat_exp",100000000);
	this_object()->set("level",589);
	return;
}

