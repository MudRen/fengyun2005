#include <localtime.h>
#include <ansi.h>

inherit F_DBASE;

mixed festivals = ([]);
mixed now_festivals = ({});
string now_string = "";
void setup();
void check_festival();
void create()
{
        seteuid(getuid());
        set("channel_id", "节日奖励精灵");   
        setup();
        check_festival();
}

void setup()
{
        // /adm/etc/festival
        // 英文名:中文名:开始时间:结束时间:节日日期:节日中文名:经验限制:奖励
        // 奖励：类型|数量,类型|数量
        string sen;
        mixed fess;
        mixed tmp,tmp2;
        int i,sz,j,sz2;
        int y,m,d;
        string reward;
        int rewardcount;
        sen = read_file("/adm/etc/festival");
        fess = explode(sen,"\n");
        sz = sizeof(fess);
        for(i=0;i<sz;i++) {
                tmp = explode(fess[i],":");
                //log_file("fes",sprintf("%O\n",tmp));
                festivals[tmp[0]] = ([]);
                festivals[tmp[0]]["cname"] = tmp[1];
                festivals[tmp[0]]["fname"] = tmp[5];
                festivals[tmp[0]]["fdate"] = tmp[4];
                festivals[tmp[0]]["stime"] = tmp[2];
                festivals[tmp[0]]["etime"] = tmp[3];
                festivals[tmp[0]]["type"] = atoi(tmp[6]);//0表示领取一次，1表示每日领取
                festivals[tmp[0]]["explimit"] = atoi(tmp[7]);
                festivals[tmp[0]]["reward"] = ([]);
                tmp2 = explode(tmp[8],",");
                sz2 = sizeof(tmp2);
                for(j=0;j<sz2;j++) {
                        sscanf(tmp2[j],"%s|%d",reward,rewardcount);
                        festivals[tmp[0]]["reward"][reward] = rewardcount;
                }
                sscanf(tmp[2],"%d-%d-%d",y,m,d);
                festivals[tmp[0]]["stimey"] = y;
                festivals[tmp[0]]["stimem"] = m;
                festivals[tmp[0]]["stimed"] = d;
                sscanf(tmp[3],"%d-%d-%d",y,m,d);
                festivals[tmp[0]]["etimey"] = y;
                festivals[tmp[0]]["etimem"] = m;        
                festivals[tmp[0]]["etimed"] = d;        
        }
}

string set_festival_string()
{
        string ret;
        mixed tmp;
        int i,sz,j,sz2;
        if(!(sz=sizeof(now_festivals))) {
                ret = HIY + "当前没有正在进行的节日活动。\n"+NOR;
        } else {
                ret = HIY+"当前正在进行中的节日活动有：\n";
                for(i=0;i<sz;i++) {
                        ret += HIY+"\t活动名称："+HIG+festivals[now_festivals[i]]["cname"]+"\n";
                        ret += HIY+"\t英文标识："+HIG+now_festivals[i]+"\n";
                        ret += HIY+"\t起始时间："+HIG+festivals[now_festivals[i]]["stime"]+"\n";
                        ret += HIY+"\t结束时间："+HIG+festivals[now_festivals[i]]["etime"]+"\n";
                        ret += HIY+"\t经验限制："+HIG+festivals[now_festivals[i]]["explimit"]+"\n";
                        ret += HIY+"\t奖励内容："+HIG;
                        tmp = keys(festivals[now_festivals[i]]["reward"]);
                        sz2 = sizeof(tmp);
                        for(j=0;j<sz2;j++) {
                                switch(tmp[j]) {
                                case "exp":
                                        ret += "经验";
                                        break;
                                case "pot":
                                        ret += "潜能";
                                        break;
                              /*  case "mar":
                                        ret += "体会";
                                        break;
                                case "neili":
                                        ret += "内力";
                                        break;
                                case "jingli":
                                        ret += "精力";
                                        break;
                                case "weiwang":
                                        ret += "威望";
                                        break;
                                case "score":
                                        ret += "阅历";
                                        break;
                                case "gongxian":
                                        ret += "贡献";
                                        break;      */
                                 case "score":
                                        ret += "评价";
                                        break;
                                case "gold":
                                        ret += "黄金";
                                        break;
                                default ://发道具的简单接口
                                write(tmp[j]);
                                      // ret+=query("name", get_object(tmp[j]));
                                        break;
                                }
                                ret += ":"+festivals[now_festivals[i]]["reward"][tmp[j]]+"，";
                        }
                        ret += "\n";
                        ret += HIY+"\t奖励类型："+HIG+((festivals[now_festivals[i]]["type"])?"每日领取":"限领一次")+"\n";
                        ret += HIY+"\t所属节日："+HIG+festivals[now_festivals[i]]["fname"]+"("+festivals[now_festivals[i]]["fdate"]+")\n\n";

                }
        }       
        ret += NOR;
        return ret;
}

string query_festival_string()
{
        return now_string;
}

int compare_date(mixed a,mixed b)
{
        //小于等于是1
        //大于是0
        if(a[0]<b[0]) {
                return 1;
        } else if(a[0]>b[0]) {
                return 0;
        } else {
                if(a[1] < b[1]) {
                        return 1;
                } else if(a[1]>b[1]) {
                        return 0;
                } else {
                        if(a[2] < b[2]) {
                                return 1;
                        } else if(a[2]>b[2]) {
                                return 0;
                        } else {
                                return 1;
                        }
                }
        }       
}

int is_festival(string arg)
{
        mixed lc;
        int y,m,d;

        lc = localtime(time());
        y = lc[LT_YEAR];
        m = lc[LT_MON] + 1;
        d = lc[LT_MDAY];

        if(!arg || undefinedp(festivals[arg]))
                return 0;

        if(compare_date(({festivals[arg]["stimey"],festivals[arg]["stimem"],festivals[arg]["stimed"]}),({y,m,d})) && compare_date(({y,m,d}),({festivals[arg]["etimey"],festivals[arg]["etimem"],festivals[arg]["etimed"]})) )
                return 1;
        return 0;
}
void check_festival()
{
        //使用节日的中文名来进行判定
        
        // 先判断是否有旧的活动过期
        int i,sz;
        mixed tmp_fes;
        mixed feskeys;
        tmp_fes = copy(now_festivals);
        if(sz = sizeof(tmp_fes)) {
                //一个一个判断
                for(i=0;i<sz;i++) {
                        if(!is_festival(tmp_fes[i])) {
                                now_festivals -= ({tmp_fes[i]});
                                	CHANNEL_D->do_sys_channel("mess","节日精灵：节日活动 "+festivals[tmp_fes[i]]["cname"]+" 结束了。");
                        }
                }
        }
        feskeys = keys(festivals);
        sz = sizeof(feskeys);
        for(i=0;i<sz;i++) {
                if(member_array(feskeys[i],now_festivals)>=0)
                        continue;
                if(is_festival(feskeys[i])) {
                        now_festivals += ({feskeys[i]});
                      	CHANNEL_D->do_sys_channel("mess", "节日精灵：节日活动 "+festivals[feskeys[i]]["cname"]+" 开始了。");
                }
        }       
        now_string = set_festival_string();
        call_out("check_festival",60);
}

string give_festival_reward(object usr,string arg)
{
        string ret;
        mixed tmp;
        int i,j,sz2;
        object ob;
        ret = "您在节日活动："+festivals[arg]["cname"]+"("+arg+")中获得了如下奖励：\n";
        tmp = keys(festivals[arg]["reward"]);
                        sz2 = sizeof(tmp);
                        for(j=0;j<sz2;j++) {
                                switch(tmp[j]) {
                                case "exp":
                                        usr->add("combat_exp", festivals[arg]["reward"][tmp[j]]);
                                        ret += "经验";
                                        break;
                                case "pot":
                                       usr->add("potential", festivals[arg]["reward"][tmp[j]], usr);
                                        ret += "潜能";
                                        break;
                               /*   case "neili":
                                       usr->add("max_neili", festivals[arg]["reward"][tmp[j]], usr);
                                        ret += "内力";
                                        break;
                                case "jingli":
                                       usr->add("max_jingli", festivals[arg]["reward"][tmp[j]], usr);
                                        ret += "精力";
                                        break;
                                case "weiwang":
                                       usr->add("weiwang", festivals[arg]["reward"][tmp[j]], usr);
                                        ret += "威望";
                                        break;
                                case "gongxian":
                                     usr->add("family/gongji", festivals[arg]["reward"][tmp[j]], usr);
                                        ret += "功绩";
                                        break;
                                        */
                                 case "score":
                                        usr->add("score", festivals[arg]["reward"][tmp[j]], usr);
                                        ret += "评价";
                                        break;
                                case "gold":
                                        ob = new("/obj/money/gold");
                                        ob->set_amount(festivals[arg]["reward"][tmp[j]]);
                                        ob->move(usr);
                                        ret += "黄金";
                                        break;
                                default ://发道具的简单接口
                                        for(i=0;i<festivals[arg]["reward"][tmp[j]];i++)  {
                                              printf(tmp[j]);
                                              ob = new(tmp[j]);
                                             ob->move(usr);
                                        }
                   
                                      ret+=get_object(tmp[j])->query("name");
                                        break;
                                }
                                ret += ":"+festivals[arg]["reward"][tmp[j]]+"，";
                        }

                        ret += "\n";
        return ret;
}

string get_reward(object usr)
{
        int i,sz;
        mixed fes_record;
        string today,ret;
        int y,m,d,ty,tm,td;
        mixed lc;

        if(!(sz=sizeof(now_festivals)))
                return "目前没有正在进行中的节日，因此没有可以领取的奖励。";    
        ret = "";       
        lc = localtime(time());
        ty = lc[LT_YEAR];
        tm = lc[LT_MON] + 1;
        td = lc[LT_MDAY];

        today = lc[LT_YEAR]+"-"+sprintf("%.2d",lc[LT_MON] + 1)+"-"+sprintf("%.2d",lc[LT_MDAY]);
        fes_record=usr->query("festival_record");
        if(!mapp(fes_record))
                fes_record = ([]);
        for(i=0;i<sz;i++) {
                //每个fes的判定和奖励。。。。
                if(undefinedp(fes_record[now_festivals[i]])) { //无记录，可领奖
                        //给奖励
                        if( usr->query("combat_exp")<festivals[now_festivals[i]]["explimit"]){
                                ret += festivals[now_festivals[i]]["cname"]+"("+now_festivals[i]+")要求经验至少为"+festivals[now_festivals[i]]["explimit"]+"，您当前经验不足，无法领取奖励。\n";
                        } else {
                                ret += give_festival_reward(usr,now_festivals[i]);
                                //加record
                                fes_record[now_festivals[i]] = today;
                        }
                } else {//有记录
                        sscanf(fes_record[now_festivals[i]],"%d-%d-%d",y,m,d);
                        if(compare_date(({festivals[now_festivals[i]]["stimey"],festivals[now_festivals[i]]["stimem"],festivals[now_festivals[i]]["stimed"]}),({y,m,d}))==0) {//奖励记录比开启更早，说明是上次节日获得，可领奖(开启时间大于奖励记录 0)
                                //给奖励
                                if( usr->query("combat_exp")<festivals[now_festivals[i]]["explimit"]){
                                         ret += festivals[now_festivals[i]]["cname"]+"("+now_festivals[i]+")要求经验至少为"+festivals[now_festivals[i]]["explimit"]+"，您当前经验不足，无法领取奖励。\n";
                                } else {
                                        ret += give_festival_reward(usr,now_festivals[i]);
                                        //加record
                                        fes_record[now_festivals[i]] = today;
                                }
                        } else { //这次领过奖了。。。
                                if(festivals[now_festivals[i]]["type"]==0) { //类型是限领一次，不给奖励
                                        ret += festivals[now_festivals[i]]["cname"]+"("+now_festivals[i]+")只能领取一次奖励，您于"+fes_record[now_festivals[i]]+"已领取过，不能再次领取。\n";
                                } else { //每日领取的
                                        if(compare_date(({ty,tm,td}),({y,m,d}))==0) { //奖励记录比今天早，可领取(今天 大于 奖励记录 0)
                                                if( usr->query("combat_exp")<festivals[now_festivals[i]]["explimit"]){
                                                        ret += festivals[now_festivals[i]]["cname"]+"("+now_festivals[i]+")要求经验至少为"+festivals[now_festivals[i]]["explimit"]+"，您当前经验不足，无法领取奖励。\n";
                                                } else {
                                                        //给奖励
                                                        ret += give_festival_reward(usr,now_festivals[i]);
                                                        //加record
                                                        fes_record[now_festivals[i]] = today;
                                                }       
                                        } else { //今天已领，不给
                                                ret += festivals[now_festivals[i]]["cname"]+"("+now_festivals[i]+")在活动期间可每日领取奖励一次，您今天（"+today+"）已经领取过奖励，不能再次领取。\n";
                                        }
                                }
                        }
                }
        }
        usr->set("festival_record", fes_record );
        return ret;
}
