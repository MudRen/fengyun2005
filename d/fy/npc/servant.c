/*	风云四随机迷宫综述 by Sinny-Silencer 

迷宫血踪
Easy boss, hard maze NPCs.
除最后一关外,所有boss都需要单人战胜。

*/


#include <ansi.h>
inherit NPC;

int 	meihuadao();
int 	shajin();

void create()
{
	set_name("铁传甲", ({ "royal servant","servant" }) );
	set("gender", "男性" );
    	set("title", "忠仆" );
	set("age", 42);
	set("per",10);
	
	set("long","
这大汗满面虬髭，目光就如鸷鹰般锐利，他是小李飞刀的贴心佣人，
向来和李探花形影不离。\n");
	
	set("combat_exp", 9000000);
	set("class","lama");
	set("attitude", "friendly");
        set("difficulty",25);
        set("reward_npc",1);
	set_skill("iron-cloth", 200);
	set_skill("jin-gang",250);
	set_skill("unarmed", 300);
	set_skill("bloodystrike", 200);
	set_skill("dodge",300);
	set_skill("move",300);
	set_skill("sky-steps",160);
	
	map_skill("dodge","sky-steps");
	map_skill("move","sky-steps");
	map_skill("unarmed", "bloodystrike");
	map_skill("iron-cloth", "jin-gang");
        
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fofawubian" :),
        }) );
	
	set("inquiry", ([
      		"李探花":  "小李飞刀，例无虚发！！！",  
      		"李寻欢": "小李飞刀，例无虚发！！！",  	
        	"梅花盗" : (: meihuadao() :),
        	"meihuadao" : (: meihuadao() :),
        	"丁乘风":	"丁氏兄妹是三清宫的主持，据传已得三清道术之精髓。\n",
        	"丁白云":	"丁氏兄妹是三清宫的主持，据传已得三清道术之精髓。\n",
        	"上官金虹":	"上官是金钱帮帮主，兵器榜上排名第二。\n",
        	"金钱帮":	"金钱帮是近年来江湖上的第一大帮，帮主上官金虹在风云城里建了总坛。\n",
   		"宣武堂":	"只知道是在金钱帮中，具体我也不清楚。\n",
   		"丰号布铺":	"丰号布铺就在风云西城外。\n",
   		"桃花瘴":	"这桃花瘴是桃花林里一种可怕的毒气，万万小心。\n",
   		"纱巾":		(: shajin() :),
   		"shajin":	(: shajin() :),
        ]));
		
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:	message_vision("$N一仰头，灌下一口烈酒。\n",this_object());
			break;
		case 1:	message_vision("$N用忧伤的眼神扫了$n一眼，似乎心里有化不开的愁。\n",this_object(),ob);
			break;
		case 2:	message_vision("$N用警惕的眼神上下打量着$n，无意中扫了一眼墙上的红布挂帘。\n",this_object(),ob);
			break;
	}
}


int	meihuadao(){
	object me, ob;
	int n;
	ob = this_object();
	me = this_player();
	if (!ob->query("in_meihuadao"))
	{
		message_vision(WHT"\n铁传甲听到梅花盗这三个字，眉头突然紧皱，一言不发。\n"NOR,me);
		return 1;
	} 	
		
	message_vision(YEL"
铁传甲啐了口带血的唾沫，恨声道：“梅花盗这不男不女的东西，嫁祸
我家少爷，千刀万剐也不为过。”\n"NOR,me);		
	
	if (REWARD_D->check_m_success(me, "桃花林探幽"))
	{
		message_vision(YEL"
$N说：多谢你替我家少爷洗去冤屈，以后有什么难事儿就来找我吧。\n"NOR,ob);
		return 1;
	}
		
	if (me->query("combat_exp")<= 100000) 			// Need exp > 100k
	{
		message_vision(CYN"
铁传甲上下打量了一下你，叹道：“你的功夫太差，枉自送了性命。。。。”\n"NOR,me);
		return 1;
	}
	if ( n = REWARD_D->riddle_check(me,"桃花林探幽"))			// ALready in progress
	{
		if (n==1)
			message_vision(CYN"
铁传甲说：“梅花盗据说在桃花林一带出没。”\n"NOR,me);
		else if (n==2)
			message_vision(CYN"
铁传甲说：“梅花盗溜了？？可找到什么线索？”\n"NOR,me);
		return 1;
	}	
	
	if (me->query("combat_exp")<= 2000000) {	
		message_vision(YEL"
铁传甲上下打量了一下你，赞道：“想我家少爷当年也是初出江湖，便名满天下，
少年人当志在四方，也好，若你能找得梅花盗的踪迹，我铁某人当谢大恩。”\n"NOR,me);
		REWARD_D->riddle_set(me, "桃花林探幽",1);		
		//me->set_temp("maze/初探桃花林",1);	
	} else 
	{		
		message_vision(YEL"
铁传甲哼了一声道：若是平时，我老铁就是四肢断尽，丢了脑袋，也不稀罕你们这 
些满口仁义的大侠的假慈悲。不过么，事关紧要，这为大侠若是能拿到梅花盗，自 
然也不错。\n"NOR,me);
		REWARD_D->riddle_set(me, "桃花林探幽",1);		
		//me->set_temp("maze/初探桃花林",2);	
	}
	
	return 1;
}


int 	shajin()
{
	object me, ob, cloth;
//	int n;
	
	ob = this_object();
	me = this_player();
			
	if (!REWARD_D->check_m_success(me,"桃花林探幽"))
	{
		message_vision(YEL"
$N一皱眉对$n说：纱巾，什么纱巾，莫非你是那梅花盗的同党不成！\n"NOR, ob, me);
		return 1;
	}
		
	if (REWARD_D->check_m_success(me, "初探金钱"))
	{
		message_vision(YEL"
$N说：纱巾之事，终于水落石出，没想到这梅花盗竟然会与金钱帮有染。\n"NOR,ob);
		return 1;	
	}
	
	if (!REWARD_D->riddle_check(me,"初探金钱"))
	{
		if (me->query("timer/maze_shajin")+900> time())
		{
			tell_object(me,"铁传甲说：当我是卖布的？过会再来吧。\n");
			return 1;	
		}
		
		message_vision(YEL"
铁传甲沉声道：你且将这块纱巾收好，可能这是梅花盗踪迹的唯一线索。 
\n铁传甲凝神道：去年时丰号布铺的那位气质高雅的少奶奶似是女红高手，
但已经很久没有在风云城听到她的消息了。 
\n铁传甲唉地一声叹了口气，递给你一块纱巾。\n\n"NOR,me);	
		cloth = new("/d/maze/npc/obj/ty-meihua_ribbon");
		cloth->set("real2",1);
		if (cloth)
		{
			if (!cloth ->move(me))
				destruct(cloth);
		}
		me->set("timer/maze_shajin",time());
		return 1;	
	}
}

int	accept_object( object who, object what) {
	
//	object cloth;
	mapping data;
	
	if (what->query("name") == HIG"缀满梅花的纱巾"NOR) 
	{
		 // We want people do this riddle by himself in one game session.
		if (!what->query("real") 
			|| (REWARD_D->riddle_check(who,"桃花林探幽") != 2))
		{
			message_vision(GRN"
铁传甲挠了挠头，嘟囔道：奇怪，这种质地的纱巾总觉得很眼熟，
究竟是在哪里见过呢？\n\n"NOR,who);
			return 0;
		}
		// Reward time.
		message_vision(YEL"
铁传甲仔细地看着缀满梅花的纱巾，满是失望地道：难道梅花盗真是只九尾狐
狸么？总是捉不到他。。。。 \n\n"NOR,who);
		
		message_vision(HIR"
铁传甲转过头来看看$N，亲切地道：自古英雄出少年，能让这只狐狸露出狐狸
尾巴也殊为不易。 \n"NOR, who);		
					
		if (!REWARD_D->check_m_success(who,"桃花林探幽"))
		{
			REWARD_D->riddle_done(who, "桃花林探幽",100, 1);
		
			data = ([
				"name":		"黄金塔：桃花林探幽",
				"target":	who,
				"att_1":	"agi",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);
		}
		
		message_vision(YEL"\n\n
铁传甲又道：这纱巾里看来名堂不小，容我仔细想想。。。。\n\n"NOR, who);	
		return 1;
		
	}
	
	if (what->query("name")=="沾满鲜血的银戟") {
		// Here, if ppl lose spear, we allow them to reget it		
		if ((REWARD_D->riddle_check(who,"初探金钱")!=2
			&& REWARD_D->riddle_check(who,"初探金钱")!=3) 
			|| !what->query("lu_spear")) {
				message_vision(BLU"
铁传甲仔细看了看沾满鲜血的银戟，沉吟片刻，无奈地摇了摇头。。。\n"NOR,who);
				return 0;
		}
		tell_object(who,WHT"
铁传甲楞楞地看着放在案几上的沾满鲜血的银戟，眉头越皱越紧，最后竟现恐惧之色。

铁传甲呆呆地抬起头，颤声道：这。。这梅花。。盗，不简单，这血里的不是普通毒
药，而是已绝迹百年的三清叛徒，妖道赤虚子私自炼制的『苍生乱』，据传这药纠集
了九天十地妖魔的诅咒，加上妖道百余年的修炼，以及。。以及数千童婴的血而制成！
如果散了开去，便如同灭绝苍生的瘟疫一般。。。

铁传甲脸上的恐惧之色愈来愈重，喃喃道：数百年前三清两位开山真人历经万难方将
此妖道兵解，这『苍生乱』又如何再现江湖？ 


铁传甲在风云阁中来回重重踱着步，突然停下对你说：事不迟宜，你且速将此戟送至
三清宫丁乘风封存，并请教『苍生乱』一事！\n\n\n"NOR); 
		what->set("lu_spear",2);
		REWARD_D->riddle_set(who,"初探金钱",3);
//		who->set("maze/送银戟",1);
	}
		return 0;
}
