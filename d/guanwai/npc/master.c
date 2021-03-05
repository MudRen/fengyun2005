inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void smart_fight();
void smart_busy();
void smart_attack();
int leave();
int init_quest();

void create()
{
	set_name("葛伦", ({ "master gelun", "master","gelun" }) );
	set("gender", "男性" );
	set("class","lama");
	set("long","葛伦高僧已在大昭寺主持多年。男女弟子遍布关外。\n");
	
	set("age", 99);

        create_family("大昭寺", 20, "主持");
    	set("rank_nogen",1);
    	set("ranks",({"藏僧","罗汉","金刚","高僧","尊者","大士","大师",
    		"上师","神僧","圣僧","法王","圣法王",YEL"大宝法王"NOR,
    		YEL"大德活佛"NOR,YEL"密宗传人"NOR,HIY"密宗宗主"NOR}));
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
						
	set("inquiry", ([
		"舍利子": "嗯....舍利子.....在舍利塔里。\n",
		"普松": "普松在大昭寺的木屋里。",
		"leave": (: leave:),
		"灵童转世":	(: init_quest :),
		"转世灵童":	(: init_quest :),
		"灵童":	(: init_quest :),
		"圣湖":	"action葛伦怒道：你竟然不知道我教圣湖所在，还读什么经书！\n",
	]) );
        
        set("combat_exp", 3000000+random(1500000));
        set("score", random(90000));
	set("reward_npc", 1);
	set("difficulty", 30);
	   
        set_skill("unarmed", 170);
        set_skill("staff", 300);
        set_skill("chanting", 190);
        set_skill("parry", 170);
        set_skill("spells",200);
        set_skill("iron-cloth", 200);
	
	set_skill("force", 170);
	set_skill("literate", 100);	
	set_skill("perception", 100);
	set_skill("bloodystrike", 200);
	set_skill("fengmo-staff", 180);
	set_skill("bolomiduo", 160);
	set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("kwan-yin-spells",200);
        set_skill("foreknowledge", 100);
    		
	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "fanwen");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "fengmo-staff");
        map_skill("parry", "fengmo-staff");
        map_skill("spells","kwan-yin-spells");
        
	set_temp("apply/iron-cloth",200);

/*      set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
		(: perform_action, "unarmed.fofawubian" :),
		(: cast_spell, "an" :),
        }) ); */
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
        	(: smart_fight() :),
        }) );
        
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}


void attempt_apprentice(object ob)
{
	if(ob->query("marry") && !ob->query("jiebai")){
		message_vision("$N叹了口气道，“施主天赋异禀，只可惜被红尘误了。”\n", this_object(), ob);
		return;
    }	
    	        
    if (ob->query("family/master_id")!="master yunsong"
		|| ob->query("family/master_name") != "云松"
		|| ob->query("class") != "lama") {
		command("shake");
		command("say 施主修为尚浅，还是去找小徒云松吧。");
		return ;
	}
	
	if (ob->query_skill("lamaism",1)< 150) {
		command("say 你的密宗佛法太差（需150级），再需潜心苦读几年。");
		return;	
	}
	
	if (REWARD_D->riddle_check(ob,"灵童转世")==6)
	{	
		message_vision(CYN"$N合掌道：善哉！善哉\n"NOR, this_object());
		command("say 你请得灵童，为本派立了大功，老衲就破例收你为徒！");
		REWARD_D->riddle_done(ob,"灵童转世",50, 1);
		command("recruit " + ob->query("id") );
		return;
	}		
				
	
	if (REWARD_D->riddle_check(ob,"灵童转世"))
	{
		command("shake");
		command("say 快去接引班禅活佛之转世灵童，不得耽搁！");
		return;
	}
	
	if (!REWARD_D->check_m_success(ob,"灵童转世")){
		command("smile");
		command("say 善哉！善哉！");
		command("say "+ ob->name(1) + "！");
		command("say 我派自葛玛拨希活佛转世至今已十五个轮回，数日前班禅活佛圆寂。");
		command("say 当务之急便是接引活佛之转世灵童。你潜心佛道多年，当可负此重任。");
		command("say 速去藏北四寺，转经千次，老衲再有安排！");
		REWARD_D->riddle_set(ob,"灵童转世",1);
		return;
	}
		
        command("smile");
        command("say 很好，很好，很好。");
        command("recruit " + ob->query("id") );
}

int init_quest(){
	object me = this_player();
	int i;
	
	if (REWARD_D->check_m_success(me,"灵童转世")) {
		command("pat "+ me->query("id"));
		return 1;
	}
	
	if (me->query("class") != "lama") {
		command("say 此事与施主无关。");
		return 1;
	}
	
	if (!REWARD_D->riddle_check(me,"灵童转世")) {
		if (me->query_skill("lamaism",1) < 150 ) {
			message_vision(CYN"$N看了看你，摇摇头低头不语。\n"NOR, this_object());
			tell_object(me,"（需１５０级密宗佛法）\n");
			return 1;
		}
		command("smile");
		command("say 善哉！善哉！");
		command("say "+ me->name(1) + "！");
		command("say 我派自葛玛拨希活佛转世至今已十五个轮回，数日前班禅活佛圆寂。");
		command("say 当务之急便是接引活佛之"YEL"转世灵童"CYN"。你入我门多年，当可负此重任。");
		command("say 速去藏北四寺，转经千次，老衲再有安排！");
		REWARD_D->riddle_set(me,"灵童转世",1);
		return 1;
	}
	
	i = REWARD_D->riddle_check(me,"灵童转世");
	
	switch (i) {
		case 1: command("say 快去藏边转经千次，方可接引转世灵童，不得耽搁！");
				return 1;		
		case 2: command("smile");
				command("spank "+ me->query("id"));
				command("say 下一步是请得前世活佛之禅杖，活佛圆寂之日，将其留在天山冰川。");
				REWARD_D->riddle_set(me,"灵童转世", 3);
				return 1;
		case 3: command("say 快去天山取得前世活佛之遗物，不得耽搁！");
				return 1;
		case 4: 
		case 999:	command("say 速持禅杖前往圣湖，观得转世灵童线索。");
					return 1;
		case 6: message_vision(CYN"$N合掌道：善哉！善哉\n"NOR, this_object());
				command("say 你请得灵童，为本派立了大功，老衲就破例收你为徒！");
				REWARD_D->riddle_done(me,"灵童转世",50, 1);
				return 1;
		default:
	}			
			
	return 1;
}
	
int accept_object(object who, object ob){
	
	if (REWARD_D->riddle_check(who,"灵童转世") == 3)
	if (ob->name() == "黑木禅杖") {
		message_vision(CYN"$N皱眉道：去了如此之久，几乎误了大事！\n"NOR, this_object());
		command("say 速持禅杖前往圣湖，观得转世灵童线索。");
		REWARD_D->riddle_set(who,"灵童转世",4);
		return 0;
	}
	
	return 0;
}			
	
	

void init()
{
//      object ob;
        ::init();
        add_action("do_killing", "kill");
/*        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }*/
}


void punish_betray(object ob)
{
        if (!ob)	return;
        if((ob->query("once_gelun")==1) && ( (ob->query("class"))!= "lama"))
          {      
			tell_object(ob, YEL"\n葛伦大怒:原来你跟赤松一样,是个背叛师门的小人！”\n"NOR);          	
          	message("vision", YEL"葛伦对"+ ob->name() +"怒道：“"+ ob->name() + "！ 忘恩负义的家伙,吃我一杖！\n"NOR, environment(ob), ob);
			tell_object(ob, HIW"葛伦一杖击在你的背上！\n"NOR);          	
          	message("vision", HIW"葛伦一杖击在"+ ob->name() +"的背上！\n"NOR, environment(ob), ob);
//          	if (ob->query_skill("cloudstaff",1)>160) ob->set_skill("cloudstaff",150);
//          	if (ob->query_skill("lamaism",1)>180)  ob->set_skill("lamaism",180);
          	tell_object(ob, HIR"你只觉天晕地转,摇摇晃晃地倒了下去----悔不当初呀!\n"NOR);
//         	ob->set("once_gelun",2);
          	ob->unconcious();
          }
}


int leave() {
	if (this_player()->query("class")!="lama") return 0;
	message_vision(CYN"$N哼了一声，“又是一个心术不正的,老夫最恨的就是你这种人。“\n"NOR, this_object());
	message_vision(CYN"$N说：若是背弃了佛祖，再也颂不得观音明咒。\n"NOR,this_object());
	message_vision(CYN"$N说：心存了妄念，这刀枪不入的金刚不坏也就只有个虚名了。\n"NOR,this_object());
	
	return 1;
}


smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2) {
		who->cast_spell("ni");
		return;
	}
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (enemy[i]->query_skill("iron-cloth")>300 
				|| enemy[i]->query("combat_exp")> who->query("combat_exp")) {
				ccommand("emote 喝道：妖孽，尝尝老衲的新本事！");
				ccommand("emote 掏出一张发黄的经纸，卷成圆筒凑近嘴边。");
				who->cast_spell("an");
				who->stop_busy();
				who->cast_spell("an");
				who->stop_busy();
				who->cast_spell("an");
				ccommand("haha");
				return;
			}		
			who->cast_spell("an");
			}
	}
	return;
}

smart_busy() {
	this_object()->perform_action("unarmed.fofawubian");
	return;
}