inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int afei();
int tower();

void create()
{
        set_name("李寻欢", ({ "li xunhuan", "li" }) );
        set("nickname", RED"小李飞刀"NOR);
        set("gender", "男性" );
        set("age", 44);
		set("class","npc");
		set("reward_npc", 1);
        set("difficulty", 40);
		set("attitude","friendly");
        set("rank_info/respect", "李探花");
        set("long",
"李寻欢别号李探花，又有江湖绰号小李飞刀。一手飞刀绝技，在百晓生的
兵器谱上排行第三。不发则已，例无虚发。\n");
        
        create_family("风云一刀", 2, "人杰");
	set("student_title","人杰");
        set("combat_exp", 40000000);
        
        set("score", 200000);
        
        set("inquiry", ([
	         "afei" : (: afei :),
	         "阿飞" : (: afei :),
	         "黄金塔": (: tower :),
	        ]) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "李寻欢不停的在咳，嘴角流下一丝鲜血。\n",
                "李寻欢的脸色越发苍白了。\n",
		"李寻欢叹口气，呆呆地望着手里的木像。\n",
        }) );
        
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
	set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
       	map_skill("throwing", "feidao");
        
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
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


void heart_beat()
{
	object feidao;
	object target;
	if(!query_temp("weapon") && is_fighting())
	{
		feidao = new(__DIR__"obj/xlfd_knife");
		feidao->move(this_object());
		command("wield flying blade");
        	target = offensive_target(this_object());
        	if(target)
        	(CLASS_D("traveller") + "/feidao/xiaoli-feidao")->kill_him(this_object(),target);
		feidao->throw_weapon(this_object(),target,0);
		return;
	}
	else
	return ::heart_beat();
}

void	init(){
	object ob;
	::init();
	
	if( interactive(ob = this_player()) && !is_fighting() ) {
                if (ob->query_temp("maze/see_li")==1) {
                        call_out("event1", 1, ob);
                        add_action("do_answer","decide");
                }
                if (ob->query_temp("maze/see_li")==2) {
                        call_out("event2", 1, ob);
                        add_action("do_answer","decide");
                }
        }

}

void event1(object me) {
	
	mapping data;
	
	if (!me || environment(me)!= environment(this_object())) {
//		command("say stop");
		return;
	}
	if (me->query_temp("is_unconcious")) {
//		command("say ok wait");
		call_out("event1",2,me);
		return;
	}
	tell_object(me,HIC"
李寻欢轻轻叹了口气，微笑着对你道：你伤势不轻，不妨多多休息一阵。 

李寻欢忽然重重地咳了起来，喘着气苦笑道：可惜那妖道赤虚并非凡人，我
虽一刀命中他的心窝，但此人幻化无方，肉身虽灭，元神尚在。。。 "NOR+HIY"

李寻欢摇了摇头苦笑道：我的小友阿飞误入罗网，身陷少林一百零八罗汉堂，
而这边金钱帮危机一触即发，哎，若是能将我劈为两个该有多好？

\n\n"NOR);
		if (REWARD_D->riddle_check( me, "再闯金钱")==4)	
		if (!REWARD_D->check_m_success(me,"再闯金钱"))
		{
			REWARD_D->riddle_done(me, "再闯金钱",100, 1);
		
			data = ([
				"name":		"黄金塔：再闯金钱",
				"target":	me,
				"att_1":	"int",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);
		}
	
	REWARD_D->riddle_set(me,"勇入少林",1);
	me->delete_temp("maze/see_li");
	return;
}

void event2(object me) {
	if (!me || environment(me)!= environment(this_object())) {
//		command("say stop");
		return;
	}
	if (me->query_temp("is_unconcious")) {
//		command("say ok wait");
		call_out("event2",2,me);
		return;
	}
	tell_object(me,YEL"
李寻欢满是歉意的看着你，苦笑道：哎，这个阿飞，幸好我和传甲及时赶到，
揭穿了百晓生，心鉴之流的阴谋，与少林冰释前嫌。否则。。 

李寻欢忽然肃然道：不过妖道赤虚拿到了无间木之后，已着手炼制苍生乱，
我等再不阻止，恐怕。。 "NOR+HIC"

李寻欢笑了笑道：不过我日前造访各大派，终于有所结果，黄金塔之战，就
在眼前！ 

李寻欢沉声道：这位"+RANK_D->query_respect(me)+"，你艺高胆大，实为此战先锋的不二人选！ 


你决定了么？(decide yes or no) \n\n\n"NOR);
//	REWARD_D->riddle_set(me,"决战黄金塔",1);
//	me->set("maze/小李再出手",1);
	me->delete_temp("maze/see_li");
	me->set_temp("maze/xiaoli_ask",1);
	return;
}

int afei(){
	object me;
	
	me = this_player();
	
	message_vision(YEL"
李寻欢摇了摇头苦笑道：我的小友阿飞误入罗网，身陷少林一百零八罗汉堂，
而这边金钱帮危机一触即发，哎，若是能将我劈为两个该有多好？\n\n"NOR,me);
	
	if (REWARD_D->riddle_check( me, "勇入少林")!=1)	
		return 1;
	
	tell_object(me,HIC"
你心头一动，想道：若是能助小李探花一臂之力，让他专心对付金钱帮的阴谋，
一腔热血，救民于火，岂不正是我辈应做之事？ "NOR+HIY"

你决定了么？（decide yes or no）

"NOR);
	me->set_temp("maze/xiaoli_ask",1);
	add_action("do_answer","decide");
	return 1;
}

int tower(){
	object me;
	
	me = this_player();

	if (REWARD_D->check_m_success(me,"决战黄金塔"))
	{	
		message_vision("too tired to write now, SINNY, what should be here?\n", me);
		return 1;
	}
		
	message_vision(CYN"
李寻欢道：赤虚拿到了无间木之后，已着手炼制苍生乱，我等再不阻止，恐怕。。 
我日前造访各大派，终于有所结果，黄金塔便是赤虚的藏匿之所。\n\n"NOR,me);
	
	if (!REWARD_D->check_m_success(me,"勇入少林"))
		return 1;
	
	tell_object(me, HIY"

李寻欢沉声道：这位"+RANK_D->query_respect(me)+"，你艺高胆大，实为此战先锋的不二人选！ 


你决定了么？(decide yes or no) \n\n\n"NOR);
	add_action("do_answer","decide");
	me->set_temp("maze/xiaoli_ask",1);
	return 1;
}
 
int do_answer(string arg){
	
	object me;
	
	me = this_player();
	if (!me->query_temp("maze/xiaoli_ask")) return 0;
		
	if (!arg)
		return notify_fail("你决定了么？\n");
	
	if (arg!= "yes" && arg!= "no")
		return notify_fail("格式decide yes或decide no。\n");
	
	if (REWARD_D->check_m_success(me,"勇入少林")) {	
		if (arg == "no") {
			message_vision("$N挠挠头，踌躇道：让我再准备一下。 \n"NOR,me);
			me ->delete_temp("maze/xiaoli_ask");
			return 1;
		}
		
		message_vision(HIR"$N长笑一声，慨然道：然，此战先锋，舍我其谁！  \n"NOR,me);
		me->delete_temp("maze/xiaoli_ask");
		REWARD_D->riddle_set(me,"决战黄金塔",1);
	} else {
		if (arg == "no") {
			tell_object(me, WHT"你仔细想了想，这件事儿太危险了，暂且不做决定为妥。\n"NOR);
			me ->delete_temp("maze/xiaoli_ask");
			return 1;
		}
		message_vision(HIC"$N下定决心，躬身道：小李探花，在下虽不才，愿赴少林搭救阿飞。 \n"NOR,me);
		command("ah");
		message_vision(CYN"$N微微笑道：好，那就辛苦你了。 \n"NOR,this_object());
		me->delete_temp("maze/xiaoli_ask");
		REWARD_D->riddle_set(me,"勇入少林",2);
	}
	return 1;
}

void attempt_apprentice (object ob) {
	
	command("smile");
	command("waggle");
	return 0;	
}

/*
void attempt_apprentice(object ob)
{
	if(time()-(int) ob->query("last_time_app_master_li") < 3600)
	{
	         message_vision("$N笑道：你怎么这么快又回来了．．．\n",this_object());
        return;
        }
	if((int) ob->query("force_factor") < 1200)
	{
	 	message_vision("$N笑道：你对武功的了解还不够．．．\n", this_object());
	return;

	}
	if( random(500) || ((int)ob->query("kar")) <  250 || query("already"))
	{
		message_vision("$N咳了两声，说道：不要开玩笑，我可不想误人子弟。\n",this_object());
		ob->set("last_time_app_master_li",time());
                return;
        }
        	command("sigh");
        	command("say 很好，" + RANK_D->query_respect(ob) + "他日切不可为非作歹。\n");
        	command("recruit " + ob->query("id") );
		ob->delete("betrayer");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "traveller");
	set("already",1);
}

void reset()
{
	set("already",0);
} 
*/