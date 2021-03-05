#include <ansi.h>
inherit ROOM;

int good_luck(object me);
int newbie_help(object me);
void init(){
	object me;
	me = this_player();
	if(interactive(me) && me->query_temp("first_time_login")) {
		me->set("NO_PK",1);
		me->set("marks/newbie_quest",1);
		call_out("newbie_help", 1, me);
	}
	add_action("do_answer", "answer");
}

int newbie_help(object me){
	tell_object(me, WHT"\n\n一团柔和的光飘近，光圈里是个有双玉色翅膀的小姑娘。\n"NOR);
	tell_object(me, WHT"只见小蝶儿笑口盈盈的说道：“欢迎来到风云世界！这位"+ RANK_D->query_respect(me) + "\n"NOR);
	tell_object(me, WHT"我是这儿的精灵小蝶儿，是否需要我来介绍一下这里的情况？”
 （answer yes/no）\n"NOR);
	me->delete_temp("first_time_login");
	me->set("marks/newbie_intro", 1); 
}

int do_answer(string arg){
	object me;
	
	me = this_player();
	if(!me->query("marks/newbie_intro")){
		return 1;
	}
	if(!arg) {
		tell_object(me, "请回答（answer yes/no）。\n");
	} else if(arg == "yes") {
		if(me->query("marks/newbie_intro") == 1){
			tell_object(me, YEL"\n小蝶儿慢慢给你讲了起来： 
新手初来乍到，先要熟悉交流的命令才可以进行下去。 
先说说交流，如果你有什么事情想让大家都知道可以用 new 命令。
例如：new 大家好！我是新来的。\n"); 
			me->ccommand("new 大家好！我是新来的。");      
			tell_object(me, YEL"\n如果你只想对你面前的人说什么，而不想让大家都知道，可以用
say 命令。\n\n例如：" + HIG"say 小蝶儿姐姐好！\n\n"YEL"      
小蝶儿接着说：“风云里有一些最基本的命令，要不要我再仔细教
给你呢？” （answer yes/no）\n"NOR); 
			me->add("marks/newbie_intro", 1);
		} else if(me->query("marks/newbie_intro") == 2) {
			tell_object(me, WHT"\n小蝶儿说道：“好吧，一个玩家的自我状态用ｉ，ｈｐ，和\n");
			tell_object(me, WHT"ｓｃｏｒｅ就可全部显示出来。\n");
			tell_object(me, HIR"\n首先是ｉ（ｉｎｖｅｎｔｏｒｙ），凡是有一个＂√＂标住的物\n");
			tell_object(me, "品表示你穿，戴，握住的物品。\n"NOR);
			me->ccommand("inventory");
			tell_object(me, HIR"\n其次是ｈｐ。\n"NOR);
			me->ccommand("hp");
			tell_object(me, HIR"\n而输入ｓｃｏｒｅ你则会看到：\n"NOR);
			me->ccommand("score");
			tell_object(me, WHT"
在风云内你可以用（ｈｅｌｐ）察看在线帮助。如果你是风云新玩家，
请先去看看新手篇（ｈｅｌｐ　ｎｅｗｂｉｅ．ｔｘｔ）。
如果你以前玩过风云类游戏，想知道风云四有什么特点，
可以看一下老手篇（ｈｅｌｐ　ａ＿ｓｋｉｌｌ．ｔｘｔ）
具体帮助你也可参看ｈｔｔｐ：／／ｗｗｗ．ｆｅｎｇｙｕｎ．ｃｏｍ。
或者到风云论坛　　http://www.fengyun.com/fy4bbs/leoboard.cgi　
希望你有一个难忘的风云之旅。”\n");
			good_luck(me);
		}
	} else {
		if(me->query("marks/newbie_intro") == 1){
			tell_object(me, YEL"
小蝶儿点点头：“这位"+ RANK_D->query_respect(me) +"很有独立精神。
噢，对了，风云城里的天机老人正在找你，到那儿打一个ｑｕｅｓｔ就可
以和他对话了。祝你好运！”
说完，小蝶儿消失了。\n"NOR);
			me->delete("marks/newbie_intro");
		} else {
			good_luck(me);
		}
	}
	return 1;
}

int good_luck(object me){
	object food, drink;
	if(me->query("marks/newbie_given_food")) {
		return 0;
	}
	tell_object(me, YEL"
小蝶儿笑笑说：“很好，看来你会很快适应这里的。
小蝶儿手中不知何时多了个翠绿的葫芦，还有一个奇异的红色果子。
小蝶儿把东西递给你说到：“这里是一些食物和饮水。希望你收下，
噢，对了，风云城里的天机老人正在找你，到那儿打一个ｑｕｅｓｔ
就可以和他对话了。祝你好运！”
说完，小蝶儿消失了。\n"NOR);
	food = new("/obj/specials/food/redfruit");
	drink = new("/obj/specials/food/calabash");
	food->move(me);
	drink->move(me);	
	me->set("marks/newbie_given_food", 1);
	me->delete("marks/newbie_intro");
}


