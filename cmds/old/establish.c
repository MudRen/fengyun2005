#define SCORE_COST 50000
#define GOLD_COST 2000
#define EXP_LIMIT 5000000
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
    string c_name,c_attri;
    string *dir;
    int i;

    seteuid(getuid());
    if(!arg || sscanf(arg,"%s %s", c_name,c_attri) != 2)
        return notify_fail("指令格式：establish <组织名称> <组织属性(正,邪 或 中立)> \n");
	if (c_attri != "正" && c_attri != "邪" && c_attri != "中立")
		return notify_fail("你只可从(正,邪 或 中立)选一个做你的组织的属性。");
	
    
    if( mapp(me->query("organization")))
        if(me->query("organization/privs")==1)
            return notify_fail("你曾经是一帮之主，不能再创立帮派了。\n");
        else if(me->query("organization/privs")==-1)
            return notify_fail("你是一帮之主，不能再创立帮派了。\n");
    
    if((int)me->query("score") < SCORE_COST)
        return notify_fail("你的评价点不够"+chinese_number(SCORE_COST)+
                           "点。\n");
	if((int)me->query("combat_exp") < EXP_LIMIT)
        return notify_fail("你的经验值不够"+chinese_number(EXP_LIMIT)+
                           "点。\n");

    if((int) me->query("deposit") < GOLD_COST*100*100)
        return notify_fail("你银行里没有"+chinese_number(GOLD_COST)+
                           "两金子。\n");
    if(!check_legal_name(c_name))
	return 1;
    dir = get_dir(DATA_DIR+"guild/");
    for(i=0; i<sizeof(dir); i++) 
        if(dir[i] == c_name)
            return notify_fail("你想创立的组织名字已经被别人占用了！\n");	
    if(!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
	return notify_fail("游戏系统出现问题！请通知管理人员！\n");
    me->delete("organization");
    me->create_organization(c_name,1,c_attri);
  //  me->set("student_title",stitle);
    me->add("score",-SCORE_COST);
    me->add("deposit",-GOLD_COST*10000);
    CHANNEL_D->do_sys_channel("info",sprintf(
        "%s(%s)于%s创立了%s派组织『%s』！",me->name(1),me->query("id"),NATURE_D->game_time(),c_attri,c_name));
    return 1;
}
 
int help(object me)
{
    write(@HELP
让你在风云中成立自己的帮派！

指令格式：bang <帮会名称> <帮主称号> <弟子称号>

此指令让你创立一个新的帮，派，或教。 

例如：

bang 雪莲教 教主 教众
创立雪莲教，你自己是雪莲教教主，你弟子是雪莲教教众

bang 瓦岗山 山大王 喽咯
创立瓦岗山，你自己是瓦岗山山大王，你弟子是瓦岗山喽咯
HELP
    );
    return 1;
}
 
int check_legal_name(string name)
{
    int i;
    i = strlen(name);
    if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
        write("对不起，中文名字必须是三到十五个中文字。\n");
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

