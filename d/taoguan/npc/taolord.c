// taolord.c
// last modified by annie,6.28.03

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string quest();

int cangsheng();
int cure();
int leave();
int marriage();
int event1(object who, int n);
void ding_fight();

void create()
{
	    set_name("丁乘风", ({ "master ding", "master", "ding chengfeng" }) );
	    set("nickname", HIG"碧海乘风" NOR);
	    set("title", "三清宫 第五代伺奉");
	    
	    set("gender", "男性");
	    set("age", 67);
	    set("long","
丁乘风原本出身武林世家，但从小好学修道降魔之术，中年后舍弃荣华富贵，与
其胞妹丁白云来到这山清水秀的三清山修行。丁乘风初时尚有好胜之心，不甘寂
寞，收了几个徒弟在江湖上闯荡，某日忽然大彻大悟，把三清宫之事尽皆交与其
妹白云观主，身边只留下几个小道童。据说他每年总有大半时候在外游历，但从
来也没人知道他的去向。\n");
	    
	    set("combat_exp", 20000000);
	    set("score", 20000);
	    set("class", "taoist");
		
/*	    create_family("三清宫", 5, "主持");
	    set("rank_nogen",1);
	    set("ranks",({"道士","小真人","真人","小天师","天师",YEL"大天师"NOR,YEL"副主持"NOR,
	                      HIY"主持"NOR}));*/
	                     
	    
	    set("reward_npc", 1);
	    set("difficulty", 40);
	    set_temp("no_dodge_snow",1);
	    
	    set("atman", 1400);
	    set("max_atman", 1400);
	    set("mana", 4000);
	    set("max_mana", 4000);
	    
		set("chat_chance_combat", 10);
	        set("chat_msg_combat", ({
	        }) );
	
	    set("inquiry", ([
	         "谷衣心法":    "谷衣心法是我三清宫为对抗邪魔外道所创的内功心法。\n",
	         "三清宫":      "我三清宫自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n",
	         "苍生乱":	(: cangsheng() :),
	         "灵药":		(: cure() :),
	         "铁传甲":	"铁传甲是李寻欢的心腹仆人。\n",
	         "李探花":  	"小李飞刀，例无虚发！！！",  
      		 "李寻欢": 	"小李飞刀，例无虚发！！！",  	
	         "上官金虹":	"上官是金钱帮帮主，兵器榜上排名第二。\n",
        	 "金钱帮":	"金钱帮是近年来江湖上的第一大帮，帮主上官金虹在风云城里建了总坛。\n",
        	 "梅花盗":	"action丁乘风紧锁眉关，一语不发。。。。\n",
	         "密牢":		"传说金钱帮在风云城总坛下建了地牢，进去的人没有一个能活着出来的。\n",
	         "冶炼高人":	"传说昆仑山下的铁矿附近多有能人，你可去那里打听。\n",
	         "冶炼":		"传说昆仑山下的铁矿附近多有能人，你可去那里打听。\n",
	         "高人":		"传说昆仑山下的铁矿附近多有能人，你可去那里打听。\n",
	         "黑洞":		"黑洞在三清山的半腰。\n",
	         "血池":		"黑洞中的绿血池，是赤虚用来炼制苍生乱的。\n",
	         "绿血池":	"黑洞中的绿血池，是赤虚用来炼制苍生乱的。\n",
	         "赤虚":		"妖道赤虚已经从黑洞中遁走，天下恐怕不得太平了。\n",
		 	"三清道术":	"三清道术一书向来由白云保管。\n",
		 	"烦恼":		 (: quest :),
	       	"job": 		(: quest :),

		]) );
	
	    set_skill("literate", 100);
	    set_skill("force", 180);
	    set_skill("move", 150);
	    set_skill("scratching", 250);
	    set_skill("spells",150);
	    set_skill("unarmed", 150);
	    set_skill("sword", 250);
	    set_skill("parry", 180);
	    set_skill("dodge", 160);
	    set_skill("gouyee", 150);
	    set_skill("notracesnow", 200);
	    set_skill("snowshade-sword", 200);
	    set_skill("alchemy",200);
	    set_skill("magic",100);	
	    set_skill("taoism", 200);
	    set_skill("scratmancy", 200);
	    set_skill("necromancy",150);
	    set_skill("perception", 100);
	    
	    map_skill("scratching", "scratmancy");
	    map_skill("parry", "snowshade-sword");
	    map_skill("sword", "snowshade-sword");
	    map_skill("move", "notracesnow");
	    map_skill("dodge", "notracesnow");
	    map_skill("spells", "necromancy");
	    map_skill("magic", "alchemy");	
	    
	    set_temp("apply/dodge", 200);
	    set_temp("apply/armor", 200);
	    
	    setup();
	
	    if (!random(10))
	    	carry_object(__DIR__"obj/sword_d1")->wield();
	    else carry_object(__DIR__"obj/sword")->wield();
	    
	    carry_object(__DIR__"obj/robe")->wear();
	    carry_object(__DIR__"obj/hat")->wear();
	    carry_object(__DIR__"obj/shoe")->wear();
}



void attempt_apprentice(object ob)
{
	    command("say 贫道闭关多年，早已不理世间俗务，拜师修道一事，需找白云观主。\n");
	    return;  
}



void init()
{	
	object me;
	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	object ob,*inv, ding, tie;
	
	ob=this_object();
	if( !me || environment(me) != environment() ) return;
		
	if (REWARD_D->check_m_success(me,"智毁血池") && !REWARD_D->riddle_check(me,"再闯金钱")
		&& !me->query_temp("maze/ding_talk_1")&& !REWARD_D->check_m_success(me,"再闯金钱")) {
		message_vision(YEL"
丁乘风看到你，脸上未有喜色，神色一变，楞楞地看着你半晌无语。 
丁乘风下定决心道：这位施主，你似是接触那沾满了苍生乱之血的银戟过久，
你。。 你已经染上了苍生乱。。。。。\n"NOR,me);
		me->set_temp("maze/ding_talk_1",1);
		return;
	}
}

void event2(object me, int num) {
	if (!me || environment(me)!= environment(this_object()) || !me->query_temp("maze/ding_talk_2")) {
	//	command("say stop");
		return;
	}
	if (me->query_temp("is_unconcious")) {
	//	command("say ok wait");
		call_out("event2",2,me,0);
		return;
	}
	tell_object(me,YEL"
等你醒来时，发现：丁乘风颓然躺倒在蒲团上，几个三清弟子围着师傅号啕大哭。
丁乘风缓缓睁开眼，微微笑道：为师还在人世，你等哭甚。 

丁乘风修炼的黑亮须发竟然变得尽白，但仍略带歉意笑道：这位施主，贫道修为
尚浅，只能将你所中的苍生乱逼于眉心处，可保得你十载平安，但。。。十载之
后，若是。。 "NOR+HIR"

丁乘风踌躇半天，终于道：若是你还无法亲手得到克制苍生乱的五种灵药，那势
必内力尽失，浑身爆裂而亡，。。。。 "NOR+HIW"

丁乘风长长叹了一口气。\n\n"NOR);
	me->delete_temp("maze/ding_talk_2");
	REWARD_D->riddle_set(me,"再闯金钱",1);
//	me->set("maze/我会死么",1);
	return;
}

int cure(){
	object me = this_player();
	if (!REWARD_D->riddle_check(me,"再闯金钱")) {
		message_vision(CYN"丁乘风说：施主好端端的，要些什么灵药！\n"NOR,me);
		return 1;
	}
	message_vision(CYN"
丁乘风苦笑道：解铃还须系铃人，这苍生乱为妖道赤虚所炼，克制的灵药自然只有
他有，据说为"NOR+HIR"『损心草』、『摧肝花』、『离魂叶』、『无间木』和『七绝枝』。"NOR+CYN"
 
丁乘风喃喃道：这妖道近日风闻已和金钱帮主上官狼狈为奸，在金钱的密牢中炼制 
活死人。哎，江湖难得太平了几十年，难道又要开始生灵涂炭，血流天下了么？ \n\n\n"NOR,me);
	REWARD_D->riddle_set(me,"再闯金钱",2);
	return 1;
}

int leave() {
		if (this_player()->query("class")!="taoist") return 0;
		message_vision(CYN"$N道。三清奇术，概不外传，你若走了可不要后悔。\n"NOR, this_object(),this_player());
		return 1;
}



int	accept_object( object who, object what) {
	
	mapping data;
	
	if (what->query("name")=="沾满鲜血的银戟") {
		if ( REWARD_D->riddle_check(who,"初探金钱")!=3
			|| what->query("lu_spear")!=2 ) {
			message_vision(CYN"
丁乘风眉关紧锁，垂目一言不发。。。。\n"NOR,who);
			return 0;
		}
		message_vision(CYN"
丁乘风目现惊恐之色，半晌无语。"NOR+HIR" 


丁乘风用拂尘卷住沾满鲜血的银戟，凝视了半晌，白皙的面色时青时红，大
汗如雨，口中喃喃有词，拂尘一摆，银戟腾空升起，直直插入金吾之鼎。刹
那之间，熊熊真火在鼎中燃起。 


丁乘风颓然盘膝坐在蒲团上，擦了擦脸上的汗，哑声道：贫道将以三味真火
此戟炼化七七四十九天，方可焚毁血中之『苍生乱』。"NOR+HIW"
 
 
丁乘风苦笑道：天上苍生，难道又要历经一场浩劫么？苍生乱啊苍生乱。。。 
他闭上双目，刹时间仿佛老去了几十年般一动不动。 


		\n"NOR,who);
		
		if (!REWARD_D->check_m_success(who,"初探金钱"))
		{
			REWARD_D->riddle_done(who, "初探金钱",100, 1);
		
			data = ([
				"name":		"黄金塔：初探金钱",
				"target":	who,
				"att_1":	"kar",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);
		}
		
		who->set("maze/毁银戟",time());
		return 1;
	}
	
	if (what->query("name")=="断剑" && what->query("guo_sword")) {
		message_vision(CYN"
丁乘风惊讶地啊了一声：这、这莫不是嵩阳铁剑！“剑在人在，剑亡人亡”，难
道郭嵩阳他已经。。。。\n\n"NOR,who);
		if (who->query("maze/得嵩阳铁剑")) {
			message_vision(CYN"
丁乘风道：此剑虽折，剑精尚存，只需找到冶炼高人，则可得其菁华。\n"NOR,who);
		}	
		else
			message_vision(CYN"
施主从何处得到这一把剑的？剑虽是宝，贪心者恐不能得之。\n"NOR,who);
		return 0;
	}

	return 0;
}
		
		
string *event1_msg=	({
	
	YEL"\n丁乘风无力地睁开双眼，长叹一声道：昔年江湖传闻我三清祖师将妖道赤虚兵解，其实
。。并不尽然，妖道肉身虽毁，但元神冥顽不灭，两位祖师无奈，只得将其封于后山黑 
洞之中。然。。百年沧桑，灵符被黑洞妖气所蚀，赤虚子业已于百日前解封，可惜我师 
兄妹二人修为不足，惨败而归，未料到今日江湖上苍生乱竟已流传。。。罪孽啊罪孽。\n"NOR,
	
	GRN"\n丁乘风忽然伏倒，颤声道：我师兄妹皆重伤不可妄动，若是这位大侠能去黑洞毁掉绿血 
池，则苍生之福矣！赤虚近日出关不知所踪，此时正是千载难得之机！ \n"NOR,
	
	YEL"\n丁乘风念动真言，写了一张符咒给你。 
丁乘风苦笑道：这一纸辟邪灵符可保你不受洞中妖魔之气所惑。\n"NOR,

	YEL"\n丁乘风又写了数道灵符，念念有辞，桃木剑往空一指，灵符燃起摇曳的火焰，却不成灰， 
反聚成团，将火种包了起来。丁乘风肃然道：这是三味真火之种，你只需将这火种投入
黑洞中的绿血池。即可将炼制苍生乱的血池毁掉。。 \n"NOR,

    	WHT"\n丁乘风叹息一声，低首不语。 \n"NOR,
    	
});

int cangsheng()	{
	
	object me;
	
	me = this_player();
	
	
	if (query("in_event_1"))
	{
		tell_object(me, "丁乘风正忙，稍等片刻。\n");
		return 1;	
	}
	
	if (REWARD_D->check_m_success(me,"智毁血池")){
		message_vision(CYN"丁乘风说：绿血池已毁，苍生乱的源头就断了。\n"NOR,me);
		return 1;
	}
	
	if (me->query_temp("maze/入三清洞穴")) {
		message_vision(HIC"丁乘风说：武林安危在此一举，你当速去消除苍生乱的血池。\n"NOR,me);
		return 1;
	}
	
	if (!REWARD_D->check_m_success(me,"初探金钱"))
	{
		message_vision(CYN"丁乘风怔怔地说：苍生乱，苍生乱，施主还是不要过问此事为好！！\n"NOR,me);
		return 1;
	}
		
	event1( me, 0);
	return 1;
}

int event1(object me, int count)
{
	object paper, seed;
				
	if (environment(me)!= environment(this_object())) 	
	{
		delete("in_event_1");
		return 1;
	}
		
	set("in_event_1",1);
	
	tell_object(me,event1_msg[count]+"\n");
		
	if(++count==sizeof(event1_msg))
	{
		delete("in_event_1");
		REWARD_D->riddle_set(me,"智毁血池",1);
		// Here we use temp mark to give ppl more seals if lost.
		me->set_temp("maze/入三清洞穴",1);	
		paper = new(AREA_MAZE"npc/obj/cv-seal");
		if (paper) {
			paper->move(me);
			paper->set("paper_owner",me);
		}
		seed = new (AREA_MAZE"npc/obj/cv-seed");
		if (seed) seed->move(me);
		return 1;
	}
	else 
		call_out("event1",1,me,count);
	return 1;
}

string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	object me = this_player();
	
	if (me->query("quest/short") == "去丁乘风处打听烦恼的事儿")
	{
		if (me->query("quest/duration") == 421)	// 除小兽
		{
				n=1+random(3);
				me->set("annie_quest/name","黑洞清除炼丹怪物");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到黑洞清除XXX"+WHT"个炼丹怪物"NOR);
				me->set("annie_quest/target","炼丹怪物");
				
				me->set("quest/short", WHT"到黑洞清除"+ n + WHT"个炼丹怪物"NOR);
				me->set("quest/location", "黑洞");
				me->set("quest/difficulty",n*30);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*60);	// 每多一个就多１分钟
				me->set("quest_time",time());
				arg= "三清半山腰的黑洞里有许多炼丹怪物，快去灭掉几个。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 422)	// 除小兽
		{
				n=1+random(3);
				me->set("annie_quest/name","黑洞清除观想兽");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到黑洞清除XXX"+WHT"个观想兽"NOR);
				me->set("annie_quest/target","观想兽");
				
				me->set("quest/short", WHT"到黑洞清除"+ n + WHT"个观想兽"NOR);
				me->set("quest/location", "黑洞");
				me->set("quest/difficulty",n*30);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*60);	// 每多一个就多１分钟
				me->set("quest_time",time());
				arg= "三清半山腰的黑洞里有许多观想兽，快去灭掉几个。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}

		return "最近好象没什么事情，你不如趁机找巫师泡泡茶吧。\n";	// error mark.
	}
	else
		return "action丁乘风笑着说：我这儿悠闲得很，不找人儿。";
	
	return " ";
}
