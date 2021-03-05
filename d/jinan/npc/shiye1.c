/* 功能 -- by Silencer@fy4
	1。列出犯人名单。
	2。打听办案手续。
	3。受贿增加犯人。
*/


inherit NPC;
inherit F_VENDOR;

#include <ansi.h> 

int info1();
int info2();
int reward;

void create()
{
        set_name("办案师爷", ({"shi ye","shiye"}));
        set("long","
所有的案子，都归此师爷管。你可用CHECK查看当前的通缉要犯名单。
目前该师爷暂时代管出售文书。\n");
        set("gender","男性");
	set("title", HIC"铁面无私"NOR);
                
        set("NO_KILL",1);
        set("combat_exp", 5000000);
	set("no_arrest",1);
	
	set("inquiry", ([
		"办案":	"缉拿犯人的事，由邢都头掌管。\n",
		"缉拿": "缉拿犯人的事，由邢都头掌管。\n",
		"巡捕": "缉拿犯人的事，由邢都头掌管。\n",
		"退休": "解职之事，由邢都头掌管。\n",
		"卸职": "解职之事，由邢都头掌管。\n",
		"通缉": "你想通缉什么人？有文书么？\n",
		"逃犯": "想知道谁是逃犯？看一下告示就知道了。\n",
		"文书":	"我这儿有空白的，你买一份填上（ｐｒｉｎｔ）犯人的名字给我。\n"
	]));
        set("vendor_goods", ([
                __DIR__"obj/gongwen" : 100,
        ]) );	
	
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
 
void init(){
	add_action("do_vendor_list","list");
	add_action("do_check","fugitive");
	::init();
}


int do_check(){
	if (this_player()->query("timer/list_pk")+2 > time())
		return notify_fail("办案师爷不耐烦地说：你不是刚来看过么？\n");
	this_player()->set("timer/list_pk",time());
	PK_D->print_pk_list();
	return 1;
}


int accept_object(object me, object item){

	string hunted_name;
	object hunted, ob;
	mapping hunted_old;
	
	ob = this_object();
	
	if (!item->query("official_seal"))
		return notify_fail("办案师爷义正词严地说：在下只收公文，不谈私事。\n");
		
	if (!hunted_name = item->query("hunted_name"))
		return notify_fail("办案师爷疑惑地说：一纸空文，于我何用？\n");
		
	hunted = find_living(hunted_name);
	if (!hunted || (hunted && hunted->query("wiz_invis")))
		return notify_fail("办案师爷沉吟片刻，抖了抖公文说：我从来没听说过这个人。\n");
	
	if (!userp(hunted))
		return notify_fail("办案师爷摇摇头说：这是你们之间的私人恩怨，本府不受理。\n");
		
	if (hunted == me)
		return notify_fail("办案师爷说：若想投案，可去济南大牢，出门向东三丈便是。\n");
		
	
	if (!hunted->query("NO_PK")) {
	if (PK_D->check_list(hunted->query("id"),"HUNTER_LIST"))
		return notify_fail("办案师爷正色道："+hunted->name()+"为本府出力，怎么可能是歹人呢？\n");
	else if (PK_D->check_list(hunted->query("id"),"PK_LIST")) 
		return notify_fail("办案师爷说：此人已经在本府的缉凶名单上了，可用check查看。\n");
	}	
	
	if (PK_D->check_list(hunted->query("id"),"PK_LIST")) {
		message_vision(CYN"办案师爷说：此人已经在本府的缉凶名单上了，可用check查看。\n",ob);
		return 1;
	}
	
	if (PK_D->count_number("PK_LIST")>=50) {
		message_vision(CYN"
办案师爷说：现在逃犯太多，积案累累，不受理新案。\n",ob);
		return 1;
	}
	
	message_vision(CYN"
办案师爷嗯了一声：『好像没听说过这个人有什么劣迹。。。。』
办案师爷在屋子里背着手踱了几圈，走到门口把门关上，坐回桌前把算盘拨弄了几下，
回身向$n微微一笑，『不过，本师爷也许可以上下打点一下，。。。。』\n"NOR,ob,me);
	reward = 10; // Default cost
	if( mapp(hunted_old = PK_D->check_list(hunted->query("id"),"PK_OLD_LIST")) ) {
		if( hunted_old["start_time"] + 388800 > time() ) {
			reward = hunted_old["reward"]*2;
			if( reward > 20 ) {
				// 死了两次以上了
				reward = 30;
			}
		}
	}
	tell_object(me, CYN"\n师爷提笔在文案纸上写了几个数字，
你斜眼一看，天哪，是"+reward+"两金子？（answer yes/no）\n"NOR);
	me->set_temp("answer_shiye1",1);
	me->set_temp("hunted_cand",hunted);
	add_action("do_answer","answer");
	return 1;
}

int do_answer(string arg){
	object me, hunted;
	object ob;
	mapping member =([
		"hunted":		"unknown",
		"name":			"unknown",
		"start_time":		0,
		"reward":		0,
		"initializer":		"none",
	]);
	
	me= this_player();
	ob= this_object();
	
	if (!me->query_temp("answer_shiye1"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no \n");
	
	if (arg == "yes") {
		if (me->query("deposit")< reward*10000) {
			tell_object(me,CYN"办案师爷冷笑一声：你恐怕没这个财力吧！\n"NOR);
			me->delete_temp("hunted_cand");
			me->delete_temp("answer_shiye1");
			return 1;
		}
		message("vision",CYN""+me->name()+"凑过去，在办案师爷的耳边这般那般地低语了几句。\n"NOR,
			environment(ob),me);
		tell_object(me,"舍不得孩子套不到狼，你咬咬牙，点点头答应了师爷。\n");
		if (!objectp(hunted = me->query_temp("hunted_cand"))) {
			message_vision(CYN"办案师爷一摊手说：晚了，此人已经失踪了。\n"NOR,me);
			me->delete_temp("hunted_cand");
			me->delete_temp("answer_shiye1");
			return 1;
		}
		if (PK_D->check_pk_list(hunted->query("id"),"PK_LIST")) {
			message_vision(CYN"办案师爷说：此人已经在本府的缉凶名单上了，可用check查看。\n",ob);
			me->delete_temp("hunted_cand");
			me->delete_temp("answer_shiye1");
			return 1;
		}
		me->add("deposit",-reward*10000);
		message_vision(CYN"办案师爷咪咪一笑，啪地一声在公文纸上盖上官府大印。\n"NOR, ob);
		me->delete_temp("hunted_cand");
		me->delete_temp("answer_shiye1");
		member["hunted"]= hunted->query("id");
		member["name"]= hunted->query("name");
		member["start_time"]= time();
		member["reward"]= reward;
		member["initializer"] = me->query("id");
		PK_D->add_member("PK_LIST",member);
		me->save();
		return 1;
	}
	
	tell_object(me,"你想了想，摇了摇头。\n");
	me->delete_temp("hunted_cand");
	me->delete_temp("answer_shiye1");
	return 1;
}


void reset()	{
	set("vendor_goods", ([
                __DIR__"obj/gongwen" : 100,
        ]) );	
}