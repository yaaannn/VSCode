import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Pattern;

public class SymmetryDate {
    public static void main(String[] args) throws ParseException {
        SymmetryDate sd = new SymmetryDate();
//        Boolean symDate = sd.isSymDate("00001000");
//        System.out.println(symDate);
        sd.symDatePrint();
    } 
    public void symDatePrint() throws ParseException {
        //定义日期的格式，方便后面比较使用
        SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd");
        //识别初始要比较的日期
        Date date = sdf.parse("10100101");
        //获取当前日期并格式化
        String today = sdf.format(new Date());
        //定义一个日历对象
        Calendar c = Calendar.getInstance();
        //判断日期是否小于当前日期
        while (Integer.valueOf(sdf.format(date))<Integer.valueOf(today)){

            //把时间转为日期格式，并判断是否满足条件，满足则输出
            if (isSymDate(sdf.format(date))){
                System.out.println(sdf.format(date));
            }
            //把日期传入日历对象中
            c.setTime(date);
            //日历增加一天
            c.add(Calendar.DAY_OF_MONTH,1);
            //根据日历获取到时间
            date = c.getTime();
        }


    }

    //判断是否满足
    public Boolean isSymDate(String date){
        if (date==null){
            return false;
        }
        if (date.length()!=8|| !Pattern.compile("\\d{8}").matcher(date).matches()){
            return false;
        }
        if (Integer.valueOf(date.substring(4,6))>12||Integer.valueOf(date.substring(6))>31){
            return false;
        }
        Set<Character> set = new HashSet<>();
        char[] cs = date.toCharArray();
        for (int i = 0; i < cs.length/2; i++) {
            if (cs[i]==cs[cs.length-1-i]){
                set.add(cs[i]);
            }else {
                return false;
            }
        }
        if (set.size()>2){
            return false;
        }
        if (!set.contains('0')&&set.size()==2){
            return false;
        }
        return true;
    }
}
