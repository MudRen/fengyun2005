#include <ansi.h>
#define LEADER_SCORE_COST 50
#define MEMBER_SCORE_COST 100
inherit F_CLEAN_UP;
/*
int check_legal_name(string name);
int check_legal_name(string name)
{
    int i;
    i = strlen(name);
    if( (strlen(name) < 4) || (strlen(name) > 12 ) ) {
        write("对不起，中文名字必须是三到六个中文字。\n");
        return 0;
    }
    while(i--) {
        if( name[i]<=' ' ) {
            write("对不起，中文名字不能用控制字元。\n");
            return 0;
        }
        if( i%2==0 && !is_chinese(name[i..<0]) ) {
            write("对不起，名字必需是中文。\n");
            return 0;
        }
    }
    return 1;
}
*/
int main(object me, string arg)
{
    object who;
	string uid, org_title;
   if(!arg || sscanf(arg,"%s %s",uid ,org_title) != 2)
	   return notify_fail("指令格式 : entitle <id> <组织中的称号>\n");
    if(me->query("organization/privs") != -1) 
        return notify_fail("你没有这种权力。\n");
    if(!objectp(who = present(uid, environment(me))) 
       || !living(who) || !userp(who))
        return notify_fail("这里没有这个玩家。\n");
    if(who->query("organization/org_name") != me->query("organization/org_name"))
        return notify_fail( who->query("name") + "并不是" + 
                            me->query("organization/org_name") + "的一份子。\n");
    if((int)me->query("score") < LEADER_SCORE_COST)
        return notify_fail( "你的评价不够"+
                            chinese_number(LEADER_SCORE_COST)+"点。\n");
	if((int)who->query("score") < MEMBER_SCORE_COST)
        return notify_fail( who->query("name")+"的评价不够"+
                            chinese_number(MEMBER_SCORE_COST)+"点。\n");
	if( strlen(org_title) > 20 )
		return notify_fail("你取的称号太长了\n");
	org_title = replace_string(org_title, "$BLK$", BLK);
	org_title = replace_string(org_title, "$RED$", RED);
	org_title = replace_string(org_title, "$GRN$", GRN);
	org_title = replace_string(org_title, "$YEL$", YEL);
	org_title = replace_string(org_title, "$BLU$", BLU);
	org_title = replace_string(org_title, "$MAG$", MAG);
	org_title = replace_string(org_title, "$CYN$", CYN);
	org_title = replace_string(org_title, "$WHT$", WHT);
	org_title = replace_string(org_title, "$HIR$", HIR);
	org_title = replace_string(org_title, "$HIG$", HIG);
	org_title = replace_string(org_title, "$HIY$", HIY);
	org_title = replace_string(org_title, "$HIB$", HIB);
	org_title = replace_string(org_title, "$HIM$", HIM);
	org_title = replace_string(org_title, "$HIC$", HIC);
	org_title = replace_string(org_title, "$HIW$", HIW);
	org_title = replace_string(org_title, "$NOR$", NOR);
    who->set("organization/org_title",org_title+NOR);
	me->add("score",-LEADER_SCORE_COST);
    who->add("score",-MEMBER_SCORE_COST);
	if (me != who)
	{
		message_vision("$N封$n为"+me->query("organization/org_name")+"的"+org_title+"\n"+NOR,me,who);
	}else
		message_vision("$N封$N自己为"+me->query("organization/org_name")+"的"+org_title+"\n"+NOR,me);
    return 1;
}
