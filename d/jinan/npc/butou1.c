/* 功能 -- by Silencer@fy4
	巡捕任免事项，查阅巡捕名单。
*/

inherit NPC;
#include <ansi.h> 


int info1();
int info2();
int reward;
mapping *hunter;

void create()
{
        set_name("邢锐", ({ "xing rui","rui" }) );
        set("long","
捕头邢锐原来是京城大镖局的总镖头，自河朔中原到关东这条线上最重要
的三十九路绿林豪杰，都曾在他手下组织成一个江湖中空前未有的超级大
镖局。近年来风云城里江湖仇杀日烈，官府势力式微，故重金聘请邢锐掌
管主持衙门事务。而铁手无情上任后独出一帜，除严令禁止械斗外，更大
胆任用江湖豪杰，悬赏缉捕凶犯。你若有意参与，可向他询问[33m缉拿[32m之事。
如果你已经是巡捕而想退出，可向他询问[33m解职[32m一事。你也可用XUNBU来查看
当前的巡捕名单。\n\n");
        set("gender","男性");
	set("title", HIR"铁手无情"NOR);
        set("age",53);
                
        set("NO_KILL",1);
        set("combat_exp", 5000000);
	set("no_arrest",1);
	
	set("inquiry", ([
		"办案":	(: info1() :),
		"巡捕": (: info1() :),
		"xunbu":(: info1() :),
		"缉拿": "学武之人当报效朝廷，主治正义，若你有意，可向我咨询巡捕
之事。巡捕并非衙门官职，但凭此身份则可追杀凶犯。\n",
		"jina": "学武之人当报效朝廷，主治正义，若你有意，可向我咨询巡捕
之事。巡捕并非衙门官职，但凭此身份则可追杀凶犯。\n",
		"解职": (: info2() :),
		"卸任": (: info2() :),
		"retire": (: info2() :),
	]));
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
 
void init(){
	add_action("do_list","xunbu");
	::init();
}


int do_list(){
	if (this_player()->query("timer/list_hunter")+2 > time())
		return notify_fail("邢锐不耐烦地说：你不是刚来看过么？\n");
	this_player()->set("timer/list_hunter",time());
	PK_D->print_hunter_list();
	return 1;
}

int info1() {
	object me, ob;
	ob = this_object();
	me = this_player();
	if (PK_D->check_list(me->query("id"),"HUNTER_LIST")) {
		message_vision("邢锐说：你已经是官封的巡捕了，还不快去办案？\n",ob);
		return 1;
	}
	
	if (PK_D->check_list(me->query("id"),"PK_LIST")) {
		message_vision("邢锐仰天打个哈哈说：强盗想当巡捕，做梦来着？\n",ob);
		return 1;
	}
	
	message_vision(CYN"
邢锐说：巡捕并非衙门官职，但凭此身份可追杀凶犯，获取赏金，但是
亦会因此卷入江湖恩怨，生死难料，你要慎重考虑。\n\n"NOR,ob);
	
	if (F_LEVEL->get_level(me->query("combat_exp"))< 20) {
		message_vision(CYN"
邢锐说：你学艺未精，恐怕不能担当如此重任，过几年再来吧（至少需等级２０）\n"NOR,ob);
		return 1;
	}
	if (PK_D->count_number("HUNTER_LIST")>=50) {
		message_vision(CYN"
邢锐说：我们已经有足够的人手了，你勇气可嘉，过一阵子再来申请吧。\n"NOR,ob);
		return 1;
	}
	
	tell_object(me,"你是否下定决心加入巡捕？（answer yes/no）\n");
	me->set_temp("answer_sima",1);
	add_action("do_answer","answer");
	return 1;
}

int info2() {
	object me, ob;
	mapping player;
	me = this_player();
	ob = this_object();
	if (!(player=PK_D->check_list(me->query("id"),"HUNTER_LIST"))) {
		message_vision("邢锐说：你又不是官封的巡捕，这事儿和你没关系。\n",ob);
		return 1;
	}
	if (player["join_time"]+86400*7 >time()) {
		message_vision("邢锐说：想来就来，想走就走，你把这儿当什么地方？（当巡捕至少一周）\n",ob);
		return 1;
	} else	{
		message_vision(CYN"
邢锐说：嗯，你也辛苦多日了，暂且隐退数日也好，不过，你在任时
结仇太多，树欲静而风不止啊，今后仍得小心。\n\n"NOR,ob);
		PK_D->remove_member("HUNTER_LIST",player->query("id"));
	}
	return 1;
}


int do_answer(string arg){
	object me, hunted;
	object ob;
	mapping member =([
		"name":			"unknown",
		"id":			"unknown",
		"join_time":		0,
		"rewarded":		0,
	]);
	
	me= this_player();
	ob= this_object();
	
	if (!me->query_temp("answer_sima"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no \n");
	
	if (arg == "yes") {
		
		if (me->query("combat_exp")<= 500000) {
			message_vision(CYN"
邢锐说：你学艺未精，恐怕不能担当如此重任，过几年再来吧。（需１８级）\n"NOR,ob);
			me->delete_temp("answer_sima");
			return 1;
		}
		message_vision(YEL"$N坚定地点了点头：匡扶正义乃我辈学武之人夙愿，在下愿当此重任。\n\n"NOR,me);
		me->delete_temp("answer_sima");
		member["name"]= me->query("name");
		member["id"] = me->query("id");
		member["join_time"] = time();
		member["rewarded"]= 0;
		
		if (PK_D->count_number("HUNTER_LIST")>=50) {
		message_vision(CYN"
邢锐说：我们已经有足够的人手了，你勇气可嘉，过一阵子再来申请吧。\n"NOR,ob);
		return 1;
		}
		
		PK_D->add_member("HUNTER_LIST",member);
		me->save();
		ob->ccommand("spank "+me->query("id"));
		message_vision(CYN"
邢锐在公文纸上写下$N的名字：好，从现在开始你就可以缉拿格杀
犯人了。办案师爷那儿有详细的名单。记住，江湖险恶，你自己也可能会遭
到暗杀，不要轻易相信任何人，包括你的同僚！\n"NOR,me);		
		return 1;
	}
	
	tell_object(me,"你犹豫半晌，摇了摇头。\n");
	me->delete_temp("answer_sima");
	return 1;
}

