<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%
	request.setCharacterEncoding("UTF-8");
	String name = request.getParameter("number");
	String id = request.getParameter("ID");
	String comment = request.getParameter("comment");
%>
<br> 글번호:<%=name%>
<br> 아이디:<%=id%>
<br> 코멘트:<%=comment%>
