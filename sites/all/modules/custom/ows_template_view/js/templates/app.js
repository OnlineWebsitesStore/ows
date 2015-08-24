var templates = angular.module('templates',['ui.bootstrap']);

templates.controller('TemplateController', function($scope, $http) {
    $scope.greeting = 'Hola!';
    $scope.currentPage = 1;
    $scope.itemsPerPage = 1;

    $http.get('json/alltemplate/data').success(function(result){
        $scope.all_templates = result;
        $scope.totalItems = $scope.all_templates.length;
        $scope.templates = $scope.all_templates.slice(0, $scope.itemsPerPage);
    });

    $http.get('json/template/data').success(function(results){
        $scope.alltemplates_data = results;
        $scope.totalItems = $scope.alltemplates_data.length;
    });

    $scope.setPage = function(tid, tid2) {
        var getProperty = function (propertyName) {
            return $scope.alltemplates_data[propertyName];
        };
        var my_tempaltes = getProperty(tid);
        if(my_tempaltes) {
            $scope.totalItems = my_tempaltes.length;
            $scope.templates = my_tempaltes.slice(0, $scope.itemsPerPage);
        } else {
            console.log('test');
            $scope.templates = new Array();
            $scope.totalItems = $scope.templates.length;
        }

    };



    $scope.pageChanged = function (currentPage) {
        var start = (currentPage - 1) * $scope.itemsPerPage;
        var end = start + $scope.itemsPerPage;
        $scope.templates =  $scope.all_templates.slice(start, end);
    };

});