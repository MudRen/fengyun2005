inherit NPC;
#include <ansi.h>
void create()
{
        set_name("徐允", ({ "xu yun","lanwood","sinny","sing girl" }) );
        set("gender", "女性" );
        set("age", 31);
        set("title", CYN"梨园七杰之"NOR);
        set("nickname", MAG"缭乱心绪自深浅"NOR);
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void do_ggyy(int count)
{
        object me;
        string msg;
		object room;
        string *event_msg = ({

CYN"\n只见得红幕拉起，台上转出几儿郎。\n"NOR,
CYN"只见一人书生打扮，倚亭着柱远眺望：\n"NOR,

MAG"那一日炉中焚宝香，夫妻举酒庆端阳。\n"NOR,
MAG"白氏妻醉卧牙床上；我与她端来醒酒汤。\n"NOR,
MAG"用手拨开红罗帐，吓得我三魂七魄飏。\n"NOR,
MAG"先只说我妻是魔障，却原来苍龙降吉祥。\n"NOR,
MAG"闷恹恹来至在江亭上，长江壮阔胜钱塘。\n"NOR,

CYN"\n只见台幕轻一转，西面二女摇橹船。\n"NOR,
CYN"四面波浪滔天起，素衫女子恨声唱：\n"NOR,

WHT"哪顾得长江波浪高，"NOR,
WHT"秃驴妒我恩爱好，"NOR,
WHT"诱骗许郎把红粉抛。\n"NOR,
WHT"一去三日无家报，活活斩断鸾凤交。\n"NOR,
WHT"望金山不由我银牙咬，青儿与我把橹摇。\n"NOR,
WHT"瞬间宝剑双出鞘，拿住了秃驴就莫轻饶！\n"NOR,

CYN"\n边上转又绕出一人，缁衣僧鞋是和尚：\n"NOR,
YEL"适才打坐文殊院，\n"NOR,
YEL"初把法华教许仙。\n"NOR,
YEL"早知道妖魔必来见，\n"NOR,
YEL"问我一声答一言。\n"NOR,

WHT"\n那许郎他与我性情一样，立下了山海誓愿作鸳鸯。\n"NOR,
WHT"望禅师开大恩将许郎放，我夫妻结草衔环永不相忘。\n"NOR,

YEL"\n那许仙他本是高德和尚，岂与妖魔女匹配鸾凰？\n"NOR,
YEL"我劝你早回转峨嵋山上，再若是混人间顷刻身亡！\n"NOR,

CYN"\n只听得青衣女子咬银牙，张口就将和尚骂：\n"NOR,

BLU"听一言不由我怒发千丈，骂一声老匹夫你细听端详：\n"NOR,
BLU"我小姐与许郎妇随夫唱，老匹夫活生生你拆散鸳鸯。\n"NOR,
BLU"放出许官人万事不讲，倘若是再迟延水涌长江！\n"NOR,

WHT"\n小青儿性粗鲁出言无状，怎比得老禅师量似海洋。\n"NOR,
WHT"我如来对众生平等供养，方感得有情者共礼空王。\n"NOR,
WHT"在湖上结良缘同来江上，与许郎怀下了九月儿郎。\n"NOR,
WHT"且替我白素贞想上一想，发下了大悲心就还我许郎。\n"NOR,

YEL"\n白素贞休得要痴心妄想，见许仙除非是倒流长江，\n"NOR,
YEL"人世间那容得害人孽障，这也是菩提心保卫善良。\n"NOR,

WHT"\n白素贞救贫病千百以上，江南人都歌颂白氏娘娘。\n"NOR,
WHT"也不知谁是那害人孽障，害得我夫妻们两下分张。\n"NOR,

YEL"\n岂不知老僧有青龙禅杖，怎能让妖魔们妄逞刁强。\n"NOR,

WHT"\n老禅师纵有那青龙禅杖，怎敌得人世间情理昭彰？\n"NOR,

BLU"\n哪有这闲言语对他来讲，姐妹们今日里大闹经堂。\n"NOR,

YEL"\n望空中叫一声护法神将!快与我擒妖孽保卫经堂！\n"NOR,

CYN"\n红幕缓缓落下，原来这堂戏又已终结。\n"NOR,
});
        me = this_object();
        msg = event_msg[count];
//        message_vision(msg,me);
		room = find_object("/d/fy/theater");
		if (!room)
			room = load_object("/d/fy/theater");
		tell_room(room,msg);
		if (count < sizeof(event_msg)-1)
                call_out("do_ggyy",1+random(2),count+1);
        return;

}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

